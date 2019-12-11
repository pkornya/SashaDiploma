#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CoolWindow *window = new CoolWindow();
    window->show();

    return app.exec();
}
