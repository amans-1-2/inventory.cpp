#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <map>

enum class ProductStatus { IN_STOCK, LOW_STOCK, OUT_OF_STOCK };
enum class ProductCategory { ELECTRONICS, CLOTHING, FOOD, FURNITURE, OTHER };

struct Product {
    int id;
    std::string name;
    ProductCategory category;
    double price;
    int quantity;
    ProductStatus status;
};

struct Product {
    int id;
    string name;
    int quantity;
};

struct Supplier {
    int id;
    string name;
    float performanceScore;
};

struct Customer {
    int id;
    string name;
};

void loadProductRecords(Product& p) {
    p.id = 101;
    p.name = "Pen";
    p.quantity = 200;
    cout << "Loaded product: " << p.name << " (ID: " << p.id << ", Quantity: " << p.quantity << ")" << endl;
}

void checkProductAvailability(Product& p) {
    cout << "Product availability for " << p.name << ": " << p.quantity << " in stock." << endl;
}

void loadSupplierRecords(Supplier& s) {
    s.id = 501;
    s.name = "ABC Supplies";
    s.performanceScore = 4.5;
    cout << "Loaded supplier: " << s.name << " (ID: " << s.id << ")" << endl;
}

void trackSupplierPerformance(Supplier& s) {
    cout << "Supplier performance score: " << s.performanceScore << endl;
}

void loadCustomerRecords(Customer& c) {
    c.id = 301;
    c.name = "Arsema";
    cout << "Loaded customer: " << c.name << " (ID: " << c.id << ")" << endl;
}

void processSale(Product& p) {
    if (p.quantity > 0) {
        p.quantity--;
        cout << "1 unit of " << p.name << " sold. Remaining: " << p.quantity << endl;
    } else {
        cout << "Sale failed. " << p.name << " is out of stock." << endl;
    }
}

void storePurchaseRecords() {
    cout << "Purchase records stored (simulated)." << endl;
}

void loadPurchaseRecords() {
    cout << "Purchase records loaded (simulated)." << endl;
}

void generateMonthlySummary() {
    cout << "Summary: 100 items sold this month." << endl;
}

void exportReportsToFile() {
    cout << "Reports exported (simulated)." << endl;
}

int main() {
    Product product;
    Supplier supplier;
    Customer customer;

    loadProductRecords(product);
    checkProductAvailability(product);

    loadSupplierRecords(supplier);
    trackSupplierPerformance(supplier);

    loadCustomerRecords(customer);
    processSale(product);

    storePurchaseRecords();
    loadPurchaseRecords();

    generateMonthlySummary();
    exportReportsToFile();

    return 0;
}

class ProductManager {
private:
    std::vector<Product> products;
    std::map<int, std::vector<std::string>> categoryMap = {
        {0, {"Electronics", "Laptops, Phones, etc."}},
        {1, {"Clothing", "Shirts, Pants, etc."}},
        {2, {"Food", "Groceries, Snacks, etc."}},
        {3, {"Furniture", "Chairs, Tables, etc."}},
        {4, {"Other", "Miscellaneous items"}}
    };

    void updateProductStatus(Product& product);

public:

    void displayAllCategories();
    ProductCategory getCategoryById(int categoryId);
    std::string getCategoryName(ProductCategory category);
    int getProductsCountByCategory(ProductCategory category);
    
 
    ProductStatus checkProductStatus(int quantity);
    void updateAllProductsStatus();
    std::vector<Product> getProductsByStatus(ProductStatus status);
    
  
};

#endif
