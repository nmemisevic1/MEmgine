#include "MEmgine.h"
#include "GraphicsEngine.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MEmgine w;

    w.show();
    return a.exec();
}
