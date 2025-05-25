#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "InventoryManager.h"
#include "InventoryItem.h"
#include "databaseManager.h"

DatabaseManager dbManager;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onAddButtonClicked();

    dbManager.connect();
    populateTable();

private:
    Ui::MainWindow *ui;
	InventoryManager inventoryManager;
    void populateTable() {
		QList<InventoryItem> items = dbManager.getAllItems();
    }
	void clearInputFields();
};
#endif // MAINWINDOW_H

