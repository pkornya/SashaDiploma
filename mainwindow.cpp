#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap picture("C:/Users/pasha/Downloads/13.png");
    ui->label_picture->setPixmap(picture);


}

MainWindow::~MainWindow()
{
    delete ui;
}
