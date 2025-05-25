#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <QString>

class InventoryItem {
public:
	QString itemType;
	QString category;
	QString description;
	QString room;
	int quantity;

	InventoryItem(const QString& itemType = "", const QString& category = "", int quantity = 0, const QString& description = "", const QString& room = "");

};

#endif //INVENTORYITEM_H