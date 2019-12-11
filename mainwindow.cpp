#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QCloseEvent>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QPushButton>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>

#include "mainwindow.h"

CoolWindow::CoolWindow(QWidget *parent) :
    QMainWindow(parent)
//    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    const QRect rect(500,500,500,500);

    setGeometry(rect);

    QPixmap picture("C:/Users/pasha/Downloads/13.png");



//    ui->label_picture->setPixmap(picture);

    // BEGIN
//    if (MainWindow->objectName().isEmpty())
//        MainWindow->setObjectName(QStringLiteral("MainWindow"));
    resize(474, 384);
    QIcon icon;
    icon.addFile(QStringLiteral("C:/Users/pasha/Downloads/systems-administrator-job-description.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    setWindowIcon(icon);

    createMainWidget();
    createSiteWidget();

    setCentralWidget(centralWidget);

    createActions();
    createMenus();

    connect(siteButton, SIGNAL(clicked(bool)), this, SLOT(on_siteButton_clicked()));
    connect(helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));

//    connect(back_button, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
//    connect(management_button, SIGNAL(pressed()), this, SLOT(on_managementButton_clicked()));
//    connect(server_button, SIGNAL(pressed()), this, SLOT(on_serverButton_clicked()));
//    connect(storage_button, SIGNAL(pressed()), this, SLOT(on_storageButton_clicked()));
//    connect(antivirus_button, SIGNAL(pressed()), this, SLOT(on_antivirusButton_clicked()));
}

void CoolWindow::createActions()
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

void CoolWindow::createMenus()
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

void CoolWindow::fileNew()
{
    (new CoolWindow())->show();
}

void CoolWindow::print()
{

}

void CoolWindow::about()
{

}

CoolWindow::~CoolWindow()
{

}

void CoolWindow::on_siteButton_clicked()
{
    if (window == nullptr)
        createSiteWidget();

    setCentralWidget(window);
    centralWidget = nullptr;

    connect(back_button, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
    disconnect(helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));
}

void CoolWindow::on_helpDeskButton_clicked()
{
    qDebug() << "Clicked";
    QDesktopServices::openUrl(QUrl("https://support.duxit.ua/issues"));

}

void CoolWindow::on_clientButton_clicked()
{

}

void CoolWindow::on_employeeButton_clicked()
{

}

void CoolWindow::on_knowledgeButton_clicked()
{

}

void CoolWindow::on_backButton_clicked()
{
    if (centralWidget == nullptr)
        createMainWidget();

    setCentralWidget(centralWidget);
    window = nullptr;

    connect(siteButton, SIGNAL(clicked(bool)), this, SLOT(on_siteButton_clicked()));
    connect(helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));
}

void CoolWindow::on_storageButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://fs.duxit.com.ua:5001/webman/index.cgi"));
}

void CoolWindow::on_managementButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://dx.sip.duxit.ua:3010/#!/login"));
}

void CoolWindow::on_serverButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://panel.online365.com.ua:8080/index.php"));
}

void CoolWindow::on_antivirusButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://era.online365.com.ua/era/webconsole/"));
}

void CoolWindow::createMainWidget()
{
    centralWidget = new QWidget();
    centralWidget->setObjectName(QStringLiteral("centralWidget"));

    label_picture = new QLabel(centralWidget);
    label_picture->setObjectName(QStringLiteral("label_picture"));
    label_picture->setGeometry(QRect(10, 10, 461, 121));
    label_picture->setScaledContents(true);

    groupBox = new QGroupBox(centralWidget);
    groupBox->setObjectName(QStringLiteral("groupBox"));
    groupBox->setGeometry(QRect(10, 150, 461, 201));

    gridLayout = new QGridLayout(groupBox);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));

    clientButton = new QPushButton("Клієнти");
    clientButton->setObjectName(QStringLiteral("clientButton"));

    gridLayout->addWidget(clientButton, 1, 0, 1, 1);

    siteButton = new QPushButton("Сайти");
    siteButton->setObjectName(QStringLiteral("siteButton"));

    gridLayout->addWidget(siteButton, 3, 0, 1, 1);

    knowledgeButton = new QPushButton("База знань");
    knowledgeButton->setObjectName(QStringLiteral("knowledgeButton"));

    gridLayout->addWidget(knowledgeButton, 3, 1, 1, 1);

    employeeButton = new QPushButton("Співробітники");
    employeeButton->setObjectName(QStringLiteral("employeeButton"));

    gridLayout->addWidget(employeeButton, 1, 1, 1, 1);

    helpDeskButton = new QPushButton("HelpDesk");
    helpDeskButton->setObjectName(QStringLiteral("helpDeskButton"));


    label_picture = new QLabel(centralWidget);
    label_picture->setObjectName(QStringLiteral("label_picture"));
    label_picture->setGeometry(QRect(10, 10, 461, 121));
    label_picture->setScaledContents(true);

    QPixmap picture("C:/Users/pasha/Downloads/Duxit FB picture.png");
    label_picture->setPixmap(picture);


    gridLayout->addWidget(helpDeskButton, 0, 0, 1, 2);
}

void CoolWindow::createSiteWidget()
{
    window = new QWidget();

    siteGroupBox = new QGroupBox(window);
    siteGroupBox->setGeometry(QRect(10, 150, 461, 201));

    layout = new QGridLayout(siteGroupBox);
    layout->setSpacing(6);
    layout->setContentsMargins(11, 11, 11, 11);

    management_button = new QPushButton("Управління телефонією");
    server_button = new QPushButton("Управління поштовим сервером");
    antivirus_button = new QPushButton("Управління антивірсуною системою");
    storage_button = new QPushButton("Файлове сховище");
    back_button = new QPushButton("Назад");

    layout->addWidget(management_button, 1, 0, 1, 1);
    layout->addWidget(server_button, 0, 0, 1, 1);
    layout->addWidget(storage_button, 0, 1, 1, 1);
    layout->addWidget(antivirus_button, 1, 1, 1, 1);
    layout->addWidget(back_button, 3, 0, 1, 2);

    connect(back_button, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
    connect(management_button, SIGNAL(pressed()), this, SLOT(on_managementButton_clicked()));
    connect(server_button, SIGNAL(pressed()), this, SLOT(on_serverButton_clicked()));
    connect(storage_button, SIGNAL(pressed()), this, SLOT(on_storageButton_clicked()));
    connect(antivirus_button, SIGNAL(pressed()), this, SLOT(on_antivirusButton_clicked()));
}
