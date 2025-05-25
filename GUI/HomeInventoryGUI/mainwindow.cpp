#include "mainwindow.h"
#include "./ui_mainwindow.h"

connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Inventory Manager logic map

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
	InventoryManager.addItem(item);
    populateTable();
    clearInputFields();

}

void MainWindow::onSaveButtonClicked() {
	InventoryManager.saveToFile("inventory.txt");
	QMessageBox::information(this, "Saved", "Inventory saved successfully.");
}

void MainWindow::onLoadButtonClicjed() {
    InventoryManager.loadFromFile("inventory.txt");
    populateTable();
}