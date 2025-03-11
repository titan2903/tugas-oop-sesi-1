#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int stock;
    string category;

public:
    // Constructor to initialize product details
    Product(int id, string name, double price, int stock, string category) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->category = category;
    }

    // Method to update the price
    void updatePrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        } else {
            cout << "Price cannot be less than 0!" << endl;
        }
    }

    // Method to update the stock
    void updateStock(int newStock) {
        if (newStock >= 0) {
            stock = newStock;
        } else {
            cout << "Stock cannot be less than 0!" << endl;
        }
    }

    // Method to display product information
    void displayInfo() const {
        cout << "Product ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: Rp." << price << ",00" << endl;
        cout << "Stock: " << stock << endl;
        cout << "Category: " << category << endl;
    }

    // Method to apply discount
    void applyDiscount(double discountPercentage) {
        if (discountPercentage > 0 && discountPercentage <= 100) {
            price -= (price * discountPercentage / 100);
        } else {
            cout << "Invalid discount percentage!" << endl;
        }
    }
};

int main() {
    // Creating a product object using the constructor
    Product product(1, "Laptop", 1000.0, 50, "Electronics");

    // Displaying product information
    product.displayInfo();

    // Updating price and stock
    product.updatePrice(950.0);
    product.updateStock(45);

    // Applying discount
    product.applyDiscount(10);

    // Displaying updated product information
    product.displayInfo();

    return 0;
}
