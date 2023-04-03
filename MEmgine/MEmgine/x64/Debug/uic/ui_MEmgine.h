/********************************************************************************
** Form generated from reading UI file 'MEmgine.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMGINE_H
#define UI_MEMGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MEmgineClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MEmgineClass)
    {
        if (MEmgineClass->objectName().isEmpty())
            MEmgineClass->setObjectName("MEmgineClass");
        MEmgineClass->resize(600, 400);
        menuBar = new QMenuBar(MEmgineClass);
        menuBar->setObjectName("menuBar");
        MEmgineClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MEmgineClass);
        mainToolBar->setObjectName("mainToolBar");
        MEmgineClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MEmgineClass);
        centralWidget->setObjectName("centralWidget");
        MEmgineClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MEmgineClass);
        statusBar->setObjectName("statusBar");
        MEmgineClass->setStatusBar(statusBar);

        retranslateUi(MEmgineClass);

        QMetaObject::connectSlotsByName(MEmgineClass);
    } // setupUi

    void retranslateUi(QMainWindow *MEmgineClass)
    {
        MEmgineClass->setWindowTitle(QCoreApplication::translate("MEmgineClass", "MEmgine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MEmgineClass: public Ui_MEmgineClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMGINE_H
