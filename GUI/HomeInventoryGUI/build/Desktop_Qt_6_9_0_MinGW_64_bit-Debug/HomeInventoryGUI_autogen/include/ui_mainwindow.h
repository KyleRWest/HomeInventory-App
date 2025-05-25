/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *itemTypeEdit;
    QLineEdit *categoryEdit;
    QSpinBox *quantitySpin;
    QPushButton *addButton;
    QTableWidget *itemTable;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QMenuBar *menubar;
    QMenu *menuHome_Inventory;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(170, 20, 361, 191));
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        itemTypeEdit = new QLineEdit(groupBox);
        itemTypeEdit->setObjectName("itemTypeEdit");
        itemTypeEdit->setGeometry(QRect(70, 20, 113, 20));
        categoryEdit = new QLineEdit(groupBox);
        categoryEdit->setObjectName("categoryEdit");
        categoryEdit->setGeometry(QRect(180, 20, 113, 20));
        quantitySpin = new QSpinBox(groupBox);
        quantitySpin->setObjectName("quantitySpin");
        quantitySpin->setGeometry(QRect(160, 40, 42, 22));
        addButton = new QPushButton(groupBox);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(140, 80, 80, 18));
        itemTable = new QTableWidget(centralwidget);
        if (itemTable->columnCount() < 6)
            itemTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        itemTable->setObjectName("itemTable");
        itemTable->setGeometry(QRect(250, 230, 221, 192));
        itemTable->setColumnCount(6);
        itemTable->horizontalHeader()->setVisible(true);
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(250, 440, 80, 18));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(390, 440, 80, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuHome_Inventory = new QMenu(menubar);
        menuHome_Inventory->setObjectName("menuHome_Inventory");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHome_Inventory->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        QTableWidgetItem *___qtablewidgetitem = itemTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = itemTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Item Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = itemTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save to File", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        menuHome_Inventory->setTitle(QCoreApplication::translate("MainWindow", "Home Inventory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
