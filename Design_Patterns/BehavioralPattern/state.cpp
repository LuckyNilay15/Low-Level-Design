#include <iostream>
#include <memory>

class VendingMachine; // Forward declaration

// 1. The State Interface
class State {
public:
    virtual ~State() = default;
    virtual void insertCoin(VendingMachine* machine) = 0;
    virtual void pressButton(VendingMachine* machine) = 0;
};

// 2. The Context Class
class VendingMachine {
private:
    State* currentState;

public:
    VendingMachine(State* initialState) : currentState(initialState) {}

    ~VendingMachine() {
        delete currentState;
    }

    void setState(State* newState) {
        delete currentState;
        currentState = newState;
    }

    void insertCoin() {
        currentState->insertCoin(this);
    }

    void pressButton() {
        currentState->pressButton(this);
    }
};

// 3. Concrete States
class NoCoinState : public State {
public:
    void insertCoin(VendingMachine* machine) override;
    void pressButton(VendingMachine* machine) override {
        std::cout << "Error: You must insert a coin first!\n";
    }
};

class HasCoinState : public State {
public:
    void insertCoin(VendingMachine* machine) override {
        std::cout << "Error: Coin already inserted!\n";
    }
    void pressButton(VendingMachine* machine) override;
};

// Transition Implementations (defined out-of-line to avoid circular dependency problems)
void NoCoinState::insertCoin(VendingMachine* machine) {
    std::cout << "Coin inserted successfully. Transitioning to Has-Coin state.\n";
    machine->setState(new HasCoinState());
}

void HasCoinState::pressButton(VendingMachine* machine) {
    std::cout << "Button pressed. Dispensing product. Transitioning back to No-Coin state.\n";
    machine->setState(new NoCoinState());
}

// 4. Demo Client Usage
int main() {
    // Start the machine in the NoCoinState
    VendingMachine* machine = new VendingMachine(new NoCoinState());

    std::cout << "--- Action 1: Pressing button without coin ---\n";
    machine->pressButton();

    std::cout << "\n--- Action 2: Inserting coin ---\n";
    machine->insertCoin();

    std::cout << "\n--- Action 3: Pressing button with coin ---\n";
    machine->pressButton();

    delete machine;
    return 0;
}
