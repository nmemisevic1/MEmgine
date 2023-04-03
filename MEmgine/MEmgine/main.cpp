#include "MEmgine.h"
#include "GraphicsEngine.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include "ViewportWidget.h"

class MyWindow : public QMainWindow
{
public:
    MyWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        QWidget* widget = new QWidget();
        viewport = new ViewportWidget();
        QVBoxLayout* layout = new QVBoxLayout();
        QPushButton* simpleButton = new QPushButton("Click me", nullptr);
        QPushButton* simpleButton2 = new QPushButton("Click me", nullptr);
        QPushButton* simpleButton3 = new QPushButton("Click me", nullptr);
        QPushButton* simpleButton4 = new QPushButton("Click me", nullptr);
        QHBoxLayout* layout2 = new QHBoxLayout();
        layout2->addWidget(simpleButton);
        layout2->addWidget(simpleButton2);
        layout2->addWidget(simpleButton3);
        layout2->addWidget(simpleButton4);
        layout->addWidget(viewport);
        layout->addLayout(layout2);
        widget->setLayout(layout);
        setCentralWidget(widget);
    }

private:
    ViewportWidget* viewport;

private:
    void updateViewport() {
        viewport->updateViewport();
    }

protected:
    void resizeEvent(QResizeEvent* event) {
        QMainWindow::resizeEvent(event);
        updateViewport();
    }

    
    void showEvent(QShowEvent* event) {
        QMainWindow::showEvent(event);
        updateViewport();
    }
    virtual bool event(QEvent* event) override {
        updateViewport();
		return QMainWindow::event(event);
	}

};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWindow window;
    window.show();

    return app.exec();
}
