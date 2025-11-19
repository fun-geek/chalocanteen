#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int price;
    int stock;
};

int main() {
    // Menu items
    Item menu[5] = {
        {"Paneer Roll", 50, 10},
        {"Chowmein", 40, 8},
        {"Juice", 30, 15},
        {"Biriyani",120,10},
        {"coffe",10,15},
    };

    int choice, qty, total = 0;
    char more;

    cout << "===== Chalo Canteen =====\n";

    do {
        // Show menu
        cout << "\nMenu:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << menu[i].name
                 << " - Rs." << menu[i].price
                 << " (Available: " << menu[i].stock << ")\n";
        }

        // Take order
        cout << "\nEnter item number: ";
        cin >> choice;
        cout << "Enter quantity: ";
        cin >> qty;

        if (choice >= 1 && choice <= 5) {
            if (qty <= menu[choice - 1].stock) {
                int cost = qty * menu[choice - 1].price;
                total += cost;
                menu[choice - 1].stock -= qty;
                cout << " Added " << qty << " x " << menu[choice - 1].name
                     << " = Rs." << cost << "\n";
            } else {
                cout<<"not enough stock available!\n";
            }
        } else {
            cout<<"Invalid choice!\n";
        }

        cout << "\nDo you want to order more? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');

    // Final bill
    cout << "\n===== BILL =====\n";
    cout << "Total Amount: Rs." << total << "\n";
    cout << "Thank you! Your food will be ready soon \n";

    return 0;
}