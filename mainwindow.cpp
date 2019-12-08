#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QCloseEvent>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPixmap>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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
