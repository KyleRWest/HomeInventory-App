#include <iostream>
#include "InventoryManager.h"
#include "InventoryItem.h"
using namespace std;

void printItems(const InventoryManager& manager) {
	auto items = manager.getItems();
	cout << "\n-- Inventory List --\n";
	for (size_t i = 0; i < items.size(); ++i) {
		cout << i + 1 << ". " << items[i].itemType
			<< "\n | Category: " << items[i].category
			<< "\n | Quantity: " << items[i].quantity <<  endl << "\n";
	}
}

int main() {
	InventoryManager manager;
	int choice;

	do {
		cout << "\n-- Home Inventory System --\n";
		cout << "1. Add Item\n";
		cout << "2. View Items\n";
		cout << "3. Update Item Quantity\n";
		cout << "4. Remove Item\n";
		cout << "5. Save to file\n";
		cout << "6. Load from file\n";
		cout << "7. Exit\n";
		cout << "Choose an option: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			string itemType, category;
			int quantity;
			cin.ignore();
			cout << "Enter item type: ";
			getline(cin, itemType);
			cout << "Enter category: ";
			getline(cin, category);
			cout << "Enter quantity: ";
			cin >> quantity;
			manager.addItem(itemType, category, quantity);
			break;
		}
		case 2: 
			printItems(manager);
			break;
		case 3: {
			size_t index;
			int quantity;
			printItems(manager);
			cout << "Enter Item to update: ";
			cin >> index;
			cout << "Enter new quantity: ";
			cin >> quantity;
			if (!manager.updateItemQuantity(index - 1, quantity))
				cout << "Invalid item number.\n";
			break;
		}
		case 4: {
			size_t index;
			printItems(manager);
			cout << "Enter item number to remove: ";
			cin >> index;
			if (!manager.removeItem(index - 1))
				cout << "Invalid item\n";
			break;
		}
		case 5: {
			if (manager.saveToFile("inventory.txt"))
				cout << "Inventory saved to file.\n";
			else
				cout << "Failed to save file.\n";
			break;
		}
		case 6: {
			if (manager.loadFromFile("inventory.txt"))
				cout << "Inventory loaded from file.\n";
			else
				cout << "Failed to load file.\n";
			break;
		}
		case 7:
			cout << "Exiting...\n";
				break;
		default:
			cout << "Invalid choice\n";
		}
	} while (choice != 7);

	return 0;
}