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
    
    // Product Status Tracking
    ProductStatus checkProductStatus(int quantity);
    void updateAllProductsStatus();
    std::vector<Product> getProductsByStatus(ProductStatus status);
    
    // Other product management functions...
};

#endif
