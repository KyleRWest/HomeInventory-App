#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <QString>

class InventoryItem {
public:
	int id; // Unique identifier for the inventory item
	QString itemType;
	QString category;
	QString description;
	QString room;
	int quantity;

	InventoryItem() = default;
	InventoryItem(QString name, QString category, QString desc, QString room, int quantity)
		: name(name), category(category), description(desc), room(room), quantity(quantity) {}

};

#endif //INVENTORYITEM_H