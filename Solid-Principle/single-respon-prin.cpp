#include <iostream>
#include <string>

class Invoice {
public:
    double amount;
    Invoice(double a) : amount(a) {}
    
    // Changing the tax rate is a business logic change
    double calculateTotal() const {
        return amount * 1.18; // 18% tax
    }
};


class InvoicePrinter {
public:
    // Changing output format (e.g., to HTML) only affects this class
    void print(const Invoice& invoice) const {
        std::cout << "Invoice Total: $" << invoice.calculateTotal() << "\n";
    }
};

class InvoiceRepository {
public:
    // Changing from File to Database only affects this class
    void saveToFile(const Invoice& invoice, const std::string& filename) const {
        std::cout << "Saving $" << invoice.calculateTotal() << " to " << filename << "\n";
    }
};





// Imagine an Invoice class. If it holds the data and also handles saving itself to a database,
// it has two reasons to change (business logic changes AND database logic changes). We split it.