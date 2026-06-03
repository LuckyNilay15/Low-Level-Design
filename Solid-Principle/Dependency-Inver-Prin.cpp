#include <iostream>
using namespace std;

// Abstraction
class IDatabase {
public:
    virtual void save() = 0;
};

// Low level module 1
class MySQLDatabase : public IDatabase {
public:
    void save() {
        cout << "Saving to MySQL...\n";
    }
};

// Low level module 2
class MongoDB : public IDatabase {
public:
    void save() {
        cout << "Saving to MongoDB...\n";
    }
};

// High level module
class Application {
    IDatabase* db; // Using a traditional raw pointer
public:
    // Simply taking the pointer and assigning it
    Application(IDatabase* database) : db(database) {}

    void processData() {
        cout << "Processing data...\n";
        db->save();
    }    
};

int main() {
    // We create the dependency using traditional "new"
    Application app(new MongoDB());
    app.processData();
    
    // You could also do:
    // MySQLDatabase* mysql = new MySQLDatabase();
    // Application app2(mysql);
    // app2.processData();

    return 0;
}