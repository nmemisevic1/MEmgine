#include "MEmgine.h"
#include "GraphicsEngine.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include "ViewportWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    ViewportWidget* viewport = new ViewportWidget();

    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    QHBoxLayout* layout2 = new QHBoxLayout();

    QPushButton* simpleButton = new QPushButton("Click me", nullptr);
    QPushButton* simpleButton2 = new QPushButton("Click me", nullptr);
    QPushButton* simpleButton3 = new QPushButton("Click me", nullptr);
    QPushButton* simpleButton4 = new QPushButton("Click me", nullptr);
    
    layout->addWidget(viewport);
    layout2->addWidget(simpleButton);
    layout2->addWidget(simpleButton2);
    layout2->addWidget(simpleButton3);
    layout2->addWidget(simpleButton4);
    layout->addLayout(layout2);
    widget->setLayout(layout);
    
    mainWindow.setCentralWidget(widget);
    mainWindow.show();

    return app.exec();
}
