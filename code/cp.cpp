#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    virtual void displayInfo() = 0;
    virtual float getPrice() = 0;
    virtual string getName() = 0;
};

class Product : public Item {
private:
    string name;
    float price;

public:
    Product() {}
    Product(string n, float p) {
        name = n;
        price = p;
    }

    void displayInfo() {
        cout << name << " - Rs " << price << endl;
    }

    float getPrice() {
        return price;
    }

    string getName() {
        return name;
    }
};

class ShoppingCart {
private:
    int customerID;
    float total;
    float finalAmount;
    int royaltyPoints;
    string items[50];
    int itemCount;

public:
    ShoppingCart() {
        customerID = 0;
        total = 0;
        finalAmount = 0;
        royaltyPoints = 0;
        itemCount = 0;
    }

    ShoppingCart(int id) {
        customerID = id;
        total = 0;
        finalAmount = 0;
        royaltyPoints = 0;
        itemCount = 0;
    }

    void addToCart(Item* item, int qty) {
        float cost = item->getPrice() * qty;
        total += cost;
        string entry = item->getName() + " x" + to_string(qty) + " = Rs " + to_string(cost);
        if (itemCount < 50) {
            items[itemCount++] = entry;
        }
    }

    void applyDiscountAndRoyalty() {
        float discount = 0;
        if (total > 10000) {
            discount = total * 0.15;
        } else if (total > 5000) {
            discount = total * 0.10;
        }
        finalAmount = total - discount;
        royaltyPoints = (int)(finalAmount / 100);
    }

    void printBill() {
        applyDiscountAndRoyalty();
        cout << "\n=== BILL for Customer ID: " << customerID << " ===\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << endl;
        }
        cout << "Total Amount: Rs " << total << endl;
        cout << "Final Amount after Discount: Rs " << finalAmount << endl;
        cout << "Royalty Points Earned: " << royaltyPoints << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    const int SIZE = 10;
    Product products[SIZE] = {
        Product("Book", 150),
        Product("Laptop", 55000),
        Product("Shirt", 800),
        Product("Pen", 10),
        Product("Phone", 25000),
        Product("Bag", 1200),
        Product("Watch", 5000),
        Product("Shoes", 2000),
        Product("Headphones", 1500),
        Product("Table", 3000)
    };

    ShoppingCart allCarts[10];
    int customerCount = 0;
    int moreCustomers = 1;

    while (moreCustomers && customerCount < 10) {
        int id;
        cout << "\nEnter Customer ID: ";
        cin >> id;

        ShoppingCart cart(id);
        int choice, quantity;

        while (true) {
            cout << "\nAvailable Products:\n";
            for (int i = 0; i < SIZE; i++) {
                cout << i + 1 << ". ";
                products[i].displayInfo();
            }

            cout << "\nEnter product number to add to cart (0 to finish): ";
            cin >> choice;

            if (choice == 0)
                break;

            if (choice < 1 || choice > SIZE) {
                cout << "Invalid choice.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> quantity;

            cart.addToCart(&products[choice - 1], quantity);
        }

        allCarts[customerCount++] = cart;

        cout << "Add another customer? (1 = Yes, 0 = No): ";
        cin >> moreCustomers;
    }

    cout << "\n=== CUSTOMER BILLS ===";
    for (int i = 0; i < customerCount; i++) {
        allCarts[i].printBill();
    }

    return 0;
}
