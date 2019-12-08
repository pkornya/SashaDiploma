#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QCloseEvent>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPixmap>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
     ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);


    QPixmap picture("C:/Users/pasha/Downloads/13.png");
    ui->label_picture->setPixmap(picture);

    createActions();
    createMenus();
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("Нове вікно"), this);
//    newAction->setIcon(QIcon(":/images/images/new.png"));
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Створити новий екземпляр програми"));
    connect(newAction, SIGNAL(triggered()),
            this, SLOT(fileNew()));

    printAction = new QAction(tr("Друк"), this);
    printAction->setIcon(QIcon(":/images/images/print.png"));
    printAction->setShortcut(tr("Ctrl+P"));
    printAction->setStatusTip(tr("Роздрукувати інформацію"));
    connect(printAction, SIGNAL(triggered(bool)),
            this, SLOT(print()));

    closeAction = new QAction(tr("Закрити"), this);
    closeAction->setIcon(QIcon(":/images/images/close.png"));
    closeAction->setShortcut(tr("Ctrl+W"));
    closeAction->setStatusTip(tr("Закрити поточне вікно"));
    connect(closeAction, SIGNAL(triggered()),
            this, SLOT(close()));

    exitAction = new QAction(tr("Вихід"), this);
    exitAction->setIcon(QIcon(":/images/images/exit.png"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Вийти з усіх вікон програми"));
    connect(exitAction, SIGNAL(triggered()),
            qApp, SLOT(closeAllWindows()));

    aboutQtAction = new QAction( tr("Про програму"), this );
    aboutQtAction->setIcon(QIcon(":/images/images/about.png"));
    aboutQtAction->setStatusTip( tr("Інформація про програму") );
    connect(aboutQtAction, SIGNAL(triggered()),
             this, SLOT(about()));
}

void MainWindow::createMenus()
{
    menu = menuBar()->addMenu(tr("&Файл"));
    menu->addAction(newAction);
    menu->addAction(printAction);
    menu->addAction(closeAction);
    menu->addSeparator();
    menu->addAction(exitAction);

    menu = menuBar()->addMenu(tr("&Допомога"));
    menu->addAction(aboutQtAction);

}

void MainWindow::fileNew()
{
    (new MainWindow())->show();
}

void MainWindow::print()
{

}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Notepad"),
            tr("<h2>Notepad 3.3 </h2>"
            "<p>Copyright &copy; 2018 Software Inc."
            "<p>Notepad is a small apllication which "
               "gives users an opportunity to work with text files "
               "and edit them. You can also print files. "
               "Ссаня сынок или доця"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
