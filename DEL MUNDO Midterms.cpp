#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Product {
private:
    int productID;
    string name, category;
    int quantity;
    double price;

public:
    Product() {}

    Product(int id, string n, int q, double p, string c) {
        productID = id;
        name = n;
        quantity = q;
        price = p;
        category = c;
    }

    void setProductID(int p) {
         productID = p; }
    int getProductID() const { 
        return productID; }

    void setName(string n) { 
        name = n; }
    string getName() const { 
        return name; }

    void setCategory(string c) {
         category = c; }
    string getCategory() const {
         return category; }

    void setQuantity(int q) { 
        quantity = q; }
    int getQuantity() const { 
        return quantity; }

    void setPrice(double p) {
        price = p; }
    double getPrice() const { 
        return price; }

    void display() const {
        cout << setw(10) << productID << setw(20) << name
             << setw(20) << category << setw(10) << quantity
             << setw(10) << fixed << setprecision(2) << price << endl;
    }
};

void displayTableHeader() {
    cout << setw(10) << "Product ID"
         << setw(20) << "Name"
         << setw(20) << "Category"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << endl;
}

int main() {
    vector<Product> inventory;
    int nextID = 1;
    int choice;

    while (true) {
        cout << "\nMenu\n"
             << "1 - Add Item\n"
             << "2 - Update Item\n"
             << "3 - Remove Item\n"
             << "4 - Display All Items\n"
             << "5 - Search Item\n"
             << "6 - Sort Items\n"
             << "7 - Display Low Stock Items\n"
             << "8 - Exit\n"
             << "Enter choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 8) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 8.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string name, category;
                int quantity;
                double price;

                cin.ignore();
                cout << "Enter item name: ";
                getline(cin, name);

                while (true) {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    if (cin.fail() || quantity < 0) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid quantity. Try again.\n";
                    } else break;
                }

                while (true) {
                    cout << "Enter price: ";
                    cin >> price;
                    if (cin.fail() || price < 0) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid price. Try again.\n";
                    } else break;
                }

                cin.ignore();
                cout << "Enter category: ";
                getline(cin, category);

                inventory.emplace_back(nextID++, name, quantity, price, category);
                cout << "Item added successfully!\n";
                break;
            }

            case 2: {
                int id;
                cout << "Enter item ID to update: ";
                cin >> id;

                for (auto& item : inventory) {
                    if (item.getProductID() == id) {
                        int updateChoice;
                        cout << "Update (1-Quantity, 2-Price): ";
                        cin >> updateChoice;

                        if (updateChoice == 1) {
                            int newQty;
                            cout << "Enter new quantity: ";
                            cin >> newQty;
                            item.setQuantity(newQty);
                            cout << "Quantity updated successfully!\n";
                        } else if (updateChoice == 2) {
                            double newPrice;
                            cout << "Enter new price: ";
                            cin >> newPrice;
                            item.setPrice(newPrice);
                            cout << "Price updated successfully!\n";
                        }
                        break;
                    }
                }
                break;
            }

            case 3: {
                int id;
                cout << "Enter item ID to remove: ";
                cin >> id;

                auto it = remove_if(inventory.begin(), inventory.end(),
                                    [id](Product& p) { return p.getProductID() == id; });
                if (it != inventory.end()) {
                    inventory.erase(it, inventory.end());
                    cout << "Item removed successfully!\n";
                } else {
                    cout << "Item not found.\n";
                }
                break;
            }

            case 4: {
                displayTableHeader();
                for (const auto& item : inventory) item.display();
                break;
            }

            case 5: {
                int id;
                cout << "Enter item ID to search: ";
                cin >> id;
                bool found = false;
                for (const auto& item : inventory) {
                    if (item.getProductID() == id) {
                        displayTableHeader();
                        item.display();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Item not found.\n";
                break;
            }

            case 6: {
                int sortChoice, order;
                cout << "Sort by: (1 - Quantity, 2 - Price): ";
                cin >> sortChoice;
                cout << "Order: (1 - Ascending, 2 - Descending): ";
                cin >> order;

                if (sortChoice == 1) {
                    sort(inventory.begin(), inventory.end(), [order](Product a, Product b) {
                        return order == 1 ? a.getQuantity() < b.getQuantity()
                                          : a.getQuantity() > b.getQuantity();
                    });
                } else if (sortChoice == 2) {
                    sort(inventory.begin(), inventory.end(), [order](Product a, Product b) {
                        return order == 1 ? a.getPrice() < b.getPrice()
                                          : a.getPrice() > b.getPrice();
                    });
                }

                displayTableHeader();
                for (const auto& item : inventory) item.display();
                break;
            }

            case 7: {
                displayTableHeader();
                for (const auto& item : inventory) {
                    if (item.getQuantity() <= 5) item.display();
                }
                break;
            }

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
