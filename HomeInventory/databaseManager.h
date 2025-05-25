#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QList>
#include <QSqlDatabase>
#include "InventoryItem.h"

class DatabaseManager {
public:
    DatabaseManager();
    bool connect();
    bool addItem(const InventoryItem& item);
    bool deleteItem(int id);
    QList<InventoryItem> getAllItems();

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
