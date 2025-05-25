#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databaseManager.cpp"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (dbManager.connect()) { // Connect to the database
        populateTable(); // Populate the table with existing items
    }
    else {
		qDebug() << "Failed to connect to the database.";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Inventory Manager button map

void MainWindow::onAddButtonClicked() {
    QString itemType = ui->itemTypeEdit->text();
    QString category = ui->categoryEdit->text();
	QString description = ui->descriptionEdit->text();
	QString room = ui->roomEdit->text();
    int quantity = ui->quantitySpin->value();

    if (itemType.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Missing input", "Please fill required fields (Item type, category).");
        return;
    }
	InventoryItem item(itemType, category, description, room, quantity);
    if (dbManager.addItem(item)) {
        populateTable(); //refresh table
    }

}

void MainWindow::onSaveButtonClicked() {
	InventoryManager.saveToFile("inventory.txt");
	QMessageBox::information(this, "Saved", "Inventory saved successfully.");
}

void MainWindow::onLoadButtonClicked() {
    InventoryManager.loadFromFile("inventory.txt");
    populateTable();
}

//SQL connection
void MainWindow::connectToDatabase() : {

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    QString dsn = "DRIVER={ODBC Driver 17 for SQL Server};"
        "SERVER=localhost;"
        "DATABASE=HomeInventory;"
        "Trusted_Connection=yes;";

    db.setDatabaseName(dsn);

    if (!db.open()) {
        qDebug() << "Database connection failed: " << db.lastError().text();
    }
    else {
        qDebug() << "Database connected successfully.";
    }
}