#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QCloseEvent>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    const QRect rect(500,500,500,500);

    setGeometry(rect);

    connect(ui->siteButton, SIGNAL(clicked(bool)), this, SLOT(on_siteButton_clicked()));
    connect(ui->helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));

    QPixmap picture("C:/Users/pasha/Downloads/13.png");
    ui->label_picture->setPixmap(picture);

    window = new QWidget;
    window->setGeometry(rect);
    management_button = new QPushButton("Управління телефонією");
    server_button = new QPushButton("Управління поштовим сервером");
    storage_button = new QPushButton("Файлове сховище");
    back_button = new QPushButton("Назад");

    layout = new QHBoxLayout;
    layout->addWidget(management_button);
    layout->addWidget(server_button);
    layout->addWidget(storage_button);
    layout->addWidget(back_button);

    window->setLayout(layout);

    connect(back_button, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_siteButton_clicked()
{
    hide();
    window->show();
}

void MainWindow::on_helpDeskButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://support.duxit.ua/issues"));
}

void MainWindow::on_clientButton_clicked()
{

}

void MainWindow::on_employeeButton_clicked()
{

}

void MainWindow::on_knowledgeButton_clicked()
{

}

void MainWindow::on_backButton_clicked()
{
    window->hide();
    show();
}
