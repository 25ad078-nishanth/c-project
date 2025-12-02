#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    int id;
    string name;
    int quantity;
    float price;

    void display() {
        cout << "ID: " << id 
             << " | Name: " << name 
             << " | Qty: " << quantity 
             << " | Price: " << price << endl;
    }
};

int main() {
    vector<Item> inventory;
    int choice;

    while (true) {
        cout << "\n==== Inventory Menu ====\n";
        cout << "1. Add Item\n2. Update Item\n3. Delete Item\n4. Display All\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Item it;
            cout << "Enter ID, Name, Qty, Price: ";
            cin >> it.id >> it.name >> it.quantity >> it.price;
            inventory.push_back(it);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;

            for (auto &it : inventory) {
                if (it.id == id) {
                    cout << "Enter new Name, Qty, Price: ";
                    cin >> it.name >> it.quantity >> it.price;
                    cout << "Updated!\n";
                }
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            for (int i = 0; i < inventory.size(); i++) {
                if (inventory[i].id == id) {
                    inventory.erase(inventory.begin() + i);
                    cout << "Deleted!\n";
                    break;
                }
            }
        }

        else if (choice == 4) {
            for (auto &it : inventory)
                it.display();
        }

        else if (choice == 5)
            break;

        else
            cout << "Invalid choice!\n";
    }
}
