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
#include <QListWidget>

#include "mainwindow.h"

CoolWindow::CoolWindow(QWidget *parent) :
    QMainWindow(parent)
//    ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    setWindowTitle("Duxit Group");
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
    icon.addFile(QStringLiteral(":/resource/images/systems-administrator-job-description.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    setWindowIcon(icon);

    createMainWidget();
    createSiteWidget();
    createKnowledgeWidget();

    setCentralWidget(centralWidget);

    createActions();
    createMenus();

    connect(siteButton, SIGNAL(clicked(bool)), this, SLOT(on_siteButton_clicked()));
    connect(helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));
    connect(employeeButton, SIGNAL(clicked(bool)), this, SLOT(on_employeeButton_clicked()));
    connect(knowledgeButton, SIGNAL(clicked(bool)), this, SLOT(on_knowledgeButton_clicked()));
    connect(FTPButton, SIGNAL(clicked(bool)), this, SLOT(on_FTPButton_clicked()));

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
    aboutQtAction->setIcon(QIcon(":/resource/images/image_2019-12-12_23-19-46.png"));
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
    if (siteWidget == nullptr)
        createSiteWidget();

    setCentralWidget(siteWidget);
    centralWidget = nullptr;

    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
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
    qDebug() << "CoolWindow::on_employeeButton_clicked()";
    employeeWidget = new QWidget();

    employeeGroupBox = new QGroupBox(employeeWidget);
    employeeGroupBox->setGeometry(QRect(10, 10, 455, 335));

    employeeGridLayout = new QGridLayout(employeeWidget);
    employeeGridLayout->setSpacing(6);
    employeeGridLayout->setContentsMargins(11, 11, 11, 11);

    sashaKravchenkoButton = new QPushButton("Саша Кравченко");
    sashaKavraskyyButton = new QPushButton("Кавраський Олександр");
    sashaArtemchukButton = new QPushButton("Артемчук Олександр");
    igorGorbButton = new QPushButton("Горб Ігор");
    sevastianKovalenkoButton = new QPushButton("Коваленко Севастьян");
    nataliaRiabaButton = new QPushButton("Ряба Наталія");
    vladislavSerdechnyyButton = new QPushButton("Сердечний Владислав");
    evgeniaTygauKravchenkoButton = new QPushButton("Тугай Євгенія");

    backButton = new QPushButton("Назад");

    employeeGridLayout->addWidget(sashaKravchenkoButton, 0, 0, 1, 1);
    employeeGridLayout->addWidget(sashaKavraskyyButton, 0, 1, 1, 1);
    employeeGridLayout->addWidget(sashaArtemchukButton, 1, 0, 1, 1);
    employeeGridLayout->addWidget(igorGorbButton, 1, 1, 1, 1);
    employeeGridLayout->addWidget(sevastianKovalenkoButton, 2, 0, 1, 1);
    employeeGridLayout->addWidget(nataliaRiabaButton, 2, 1, 1, 1);
    employeeGridLayout->addWidget(vladislavSerdechnyyButton, 3, 0, 1, 1);
    employeeGridLayout->addWidget(evgeniaTygauKravchenkoButton, 3, 1, 1, 1);
    employeeGridLayout->addWidget(backButton, 4, 0, 1, 2);

    setCentralWidget(employeeWidget);
    centralWidget = siteWidget = nullptr;

    connect(sashaKravchenkoButton, SIGNAL(pressed()), this, SLOT(on_sashaButton_clicked()));
    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
}

void CoolWindow::on_knowledgeButton_clicked()
{
    qDebug() << "CoolWindow::on_knowledgeButton_clicked()";
    setCentralWidget(knowledgeWidget);
    centralWidget = siteWidget = nullptr;

//    connect(sashaKravchenkoButton, SIGNAL(pressed()), this, SLOT(on_sashaButton_clicked()));
    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));

}

void CoolWindow::on_backButton_clicked()
{
    qDebug() << "on_backButton_clicked()";
    if (centralWidget == nullptr)
        createMainWidget();

    setCentralWidget(centralWidget);
    siteWidget = nullptr;

    connect(siteButton, SIGNAL(clicked(bool)), this, SLOT(on_siteButton_clicked()));
    connect(helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));
    connect(employeeButton, SIGNAL(clicked(bool)), this, SLOT(on_employeeButton_clicked()));
    connect(knowledgeButton, SIGNAL(clicked(bool)), this, SLOT(on_knowledgeButton_clicked()));
}

void CoolWindow::on_storageButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://fs.duxit.com.ua:5001/webman/index.cgi"));
}

void CoolWindow::on_managementButton_clicked()
{
    qDebug() << "on_managementButton_clicked()";
    QDesktopServices::openUrl(QUrl("https://dx.sip.duxit.ua:3010/#!/login"));
}

void CoolWindow::on_serverButton_clicked()
{
    qDebug() << "on_serverButton_clicked()";
    QDesktopServices::openUrl(QUrl("https://panel.online365.com.ua:8080/index.php"));
}

void CoolWindow::on_antivirusButton_clicked()
{
    qDebug() << "on_antivirusButton_clicked()";
    QDesktopServices::openUrl(QUrl("https://era.online365.com.ua/era/webconsole/"));
}

void CoolWindow::createMainWidget()
{
    centralWidget = new QWidget();
    centralWidget->setObjectName(QStringLiteral("centralWidget"));

    centralLabelPicture = new QLabel(centralWidget);
    centralLabelPicture->setObjectName(QStringLiteral("label_picture"));
    centralLabelPicture->setGeometry(QRect(10, 10, 461, 121));
    centralLabelPicture->setScaledContents(true);

    centralGroupBox = new QGroupBox(centralWidget);
    centralGroupBox->setObjectName(QStringLiteral("groupBox"));
    centralGroupBox->setGeometry(QRect(10, 150, 461, 201));

    centralGridLayout = new QGridLayout(centralGroupBox);
    centralGridLayout->setSpacing(6);
    centralGridLayout->setContentsMargins(11, 11, 11, 11);
    centralGridLayout->setObjectName(QStringLiteral("gridLayout"));

    clientButton = new QPushButton("Клієнти");
    clientButton->setObjectName(QStringLiteral("clientButton"));

    centralGridLayout->addWidget(clientButton, 1, 0, 1, 1);

    siteButton = new QPushButton("Наші ресурси");
    siteButton->setObjectName(QStringLiteral("siteButton"));

    centralGridLayout->addWidget(siteButton, 3, 0, 1, 1);

    knowledgeButton = new QPushButton("База знань");
    knowledgeButton->setObjectName(QStringLiteral("knowledgeButton"));

    centralGridLayout->addWidget(knowledgeButton, 3, 1, 1, 1);

    employeeButton = new QPushButton("Співробітники");
    employeeButton->setObjectName(QStringLiteral("employeeButton"));

    centralGridLayout->addWidget(employeeButton, 1, 1, 1, 1);

    helpDeskButton = new QPushButton("HelpDesk");
    helpDeskButton->setObjectName(QStringLiteral("helpDeskButton"));


    centralLabelPicture = new QLabel(centralWidget);
    centralLabelPicture->setObjectName(QStringLiteral("label_picture"));
    centralLabelPicture->setGeometry(QRect(10, 10, 455, 155));
    centralLabelPicture->setScaledContents(true);

    QPixmap picture(":/resource/images/Duxit FB picture_1.png");
    centralLabelPicture->setPixmap(picture);


    centralGridLayout->addWidget(helpDeskButton, 0, 0, 1, 2);
}

void CoolWindow::createSiteWidget()
{
    siteWidget = new QWidget();

    siteGroupBox = new QGroupBox(siteWidget);
    siteGroupBox->setGeometry(QRect(10, 150, 440, 201));

    siteGridLayout = new QGridLayout(siteGroupBox);
    siteGridLayout->setSpacing(6);
    siteGridLayout->setContentsMargins(11, 11, 11, 11);

    managementButton = new QPushButton("Управління телефонією");
    serverButton = new QPushButton("Управління поштовим сервером");
    antivirusButton = new QPushButton("Управління антивірсуною системою");
    storageButton = new QPushButton("Файлове сховище");
    backButton = new QPushButton("Назад");

    siteGridLayout->addWidget(managementButton, 1, 0, 1, 1);
    siteGridLayout->addWidget(serverButton, 0, 0, 1, 1);
    siteGridLayout->addWidget(storageButton, 0, 1, 1, 1);
    siteGridLayout->addWidget(antivirusButton, 1, 1, 1, 1);
    siteGridLayout->addWidget(backButton, 3, 0, 1, 2);

    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
    connect(managementButton, SIGNAL(pressed()), this, SLOT(on_managementButton_clicked()));
    connect(serverButton, SIGNAL(pressed()), this, SLOT(on_serverButton_clicked()));
    connect(storageButton, SIGNAL(pressed()), this, SLOT(on_storageButton_clicked()));
    connect(antivirusButton, SIGNAL(pressed()), this, SLOT(on_antivirusButton_clicked()));
}


void CoolWindow::on_sashaButton_clicked()
{
    qDebug() << "on_sashaButton_clicked()";
    sashaKranchenko = new EmployeeSashaKravchenko();

    sashaKranchenko->show();
}

void CoolWindow::on_FTPButton_clicked()
{
    FTPWidget = new QWidget();

    FTPGroupBox = new QGroupBox(FTPWidget);
    FTPGroupBox->setGeometry(QRect(10, 150, 440, 201));

    FTPGridLayout = new QGridLayout(FTPGroupBox);
    FTPGridLayout->setSpacing(6);
    FTPGridLayout->setContentsMargins(11, 11, 11, 11);

    VPNButton = new QPushButton("Налаштування VPN для Windows");
    fakeButton = new QPushButton("Додавання мережевих дисків");

    FTPGridLayout->addWidget(VPNButton, 1, 0, 1, 1);
    FTPGridLayout->addWidget(fakeButton, 0, 0, 1, 1);

    setCentralWidget(FTPWidget);
}

void CoolWindow::createKnowledgeWidget()
{
    knowledgeWidget = new QWidget();

    knowledgeGroupBox = new QGroupBox(knowledgeWidget);
    knowledgeGroupBox->setGeometry(QRect(10, 10, 455, 335));

    knowledgeGridLayout = new QGridLayout(knowledgeWidget);
    knowledgeGridLayout->setSpacing(6);
    knowledgeGridLayout->setContentsMargins(11, 11, 11, 11);

    FTPButton = new QPushButton("FTP");
    globalButton = new QPushButton("Global");
    titanButton = new QPushButton("Titan");
    aeroButton = new QPushButton("Aero");
    spyceButton = new QPushButton("Spyce");

    backButton = new QPushButton("Назад");

    knowledgeGridLayout->addWidget(FTPButton, 0, 0, 1, 1);
    knowledgeGridLayout->addWidget(globalButton, 0, 1, 1, 1);
    knowledgeGridLayout->addWidget(titanButton, 1, 0, 1, 1);
    knowledgeGridLayout->addWidget(aeroButton, 1, 1, 1, 1);
    knowledgeGridLayout->addWidget(spyceButton, 2, 0, 1, 1);
    knowledgeGridLayout->addWidget(backButton, 3, 0, 1, 2);

}
