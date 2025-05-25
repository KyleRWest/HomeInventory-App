#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::connect() {
    db = QSqlDatabase::addDatabase("QODBC");
    QString dsn = "DRIVER={ODBC Driver 17 for SQL Server};"
        "SERVER=localhost\\SQLEXPRESS;"
        "DATABASE=HomeInventoryDB;"
        "Trusted_Connection=yes;";
    db.setDatabaseName(dsn);

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    qDebug() << "Connected to SQL Server";
    return true;
}

bool DatabaseManager::addItem(const InventoryItem& item) {
    QSqlQuery query;
    query.prepare("EXEC AddInventoryItem :name, :category, :description, :room, :quantity");
    query.bindValue(":name", item.name);
    query.bindValue(":category", item.category);
    query.bindValue(":description", item.description);
    query.bindValue(":room", item.room);
    query.bindValue(":quantity", item.quantity);
    return query.exec();
}

bool DatabaseManager::deleteItem(int id) {
    QSqlQuery query;
    query.prepare("EXEC DeleteInventoryItem :id");
    query.bindValue(":id", id);
    return query.exec();
}

QList<InventoryItem> DatabaseManager::getAllItems() {
    QList<InventoryItem> itemList;
    QSqlQuery query("EXEC GetAllInventoryItems");

    while (query.next()) {
        InventoryItem item;
        item.id = query.value("Id").toInt();
        item.name = query.value("Name").toString();
        item.category = query.value("Category").toString();
        item.description = query.value("Description").toString();
        item.room = query.value("Room").toString();
        item.quantity = query.value("Quantity").toInt();
        itemList.append(item);
    }

    return itemList;
}
