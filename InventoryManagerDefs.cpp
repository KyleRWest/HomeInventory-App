#include "InventoryItem.h"

InventoryItem::InventoryItem(const QString& name,
    const QString& category,
    const QString& description,
    const QString& room,
    int quantity)
    : name(name), category(category), description(description), room(room), quantity(quantity) {
}
