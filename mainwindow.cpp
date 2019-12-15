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
#include <QMessageBox>


#include "mainwindow.h"

CoolWindow::CoolWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Duxit Group");
    setAttribute(Qt::WA_DeleteOnClose);

    const QRect rect(500,500,500,500);

    setGeometry(rect);

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
}

void CoolWindow::createActions()
{
    newAction = new QAction(tr("Нове вікно"), this);
    newAction->setIcon(QIcon(":/resource/images/new.png"));
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Створити новий екземпляр програми"));
    connect(newAction, SIGNAL(triggered()),
            this, SLOT(fileNew()));

    printAction = new QAction(tr("Друк"), this);
    printAction->setIcon(QIcon(":/resource/images/print.png"));
    printAction->setShortcut(tr("Ctrl+P"));
    printAction->setStatusTip(tr("Роздрукувати інформацію"));
    connect(printAction, SIGNAL(triggered(bool)),
            this, SLOT(print()));

    closeAction = new QAction(tr("Закрити"), this);
    closeAction->setIcon(QIcon(":/resource/images/close.png"));
    closeAction->setShortcut(tr("Ctrl+W"));
    closeAction->setStatusTip(tr("Закрити поточне вікно"));
    connect(closeAction, SIGNAL(triggered()),
            this, SLOT(close()));

    exitAction = new QAction(tr("Вихід"), this);
    exitAction->setIcon(QIcon(":/resource/images/exit.png"));
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Вийти з усіх вікон програми"));
    connect(exitAction, SIGNAL(triggered()),
            qApp, SLOT(closeAllWindows()));

    aboutQtAction = new QAction( tr("Про програму"), this );
    aboutQtAction->setIcon(QIcon(":/resource/images/about.png"));
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

void CoolWindow::createMainWidget()
{
    centralWidget = new QWidget();
    centralWidget->setObjectName(QStringLiteral("centralWidget"));

//    centralLabelPicture = new QLabel(centralWidget);
//    centralLabelPicture->setObjectName(QStringLiteral("label_picture"));
//    centralLabelPicture->setGeometry(QRect(10, 10, 461, 121));
//    centralLabelPicture->setScaledContents(true);

    centralGroupBox = new QGroupBox(centralWidget);
    centralGroupBox->setObjectName(QStringLiteral("groupBox"));
    centralGroupBox->setGeometry(QRect(10, 180, 455, 201));

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

    connect(siteButton, SIGNAL(clicked(bool)), this, SLOT(on_siteButton_clicked()));
    connect(helpDeskButton, SIGNAL(clicked(bool)), this, SLOT(on_helpDeskButton_clicked()));
    connect(employeeButton, SIGNAL(clicked(bool)), this, SLOT(on_employeeButton_clicked()));
    connect(knowledgeButton, SIGNAL(clicked(bool)), this, SLOT(on_knowledgeButton_clicked()));
    connect(clientButton, SIGNAL(clicked(bool)), this, SLOT(on_clientButton_clicked()));
}

void CoolWindow::createSiteWidget()
{
    siteWidget = new QWidget();

    siteGroupBox = new QGroupBox(siteWidget);
    siteGroupBox->setGeometry(QRect(10, 180, 455, 201));

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

    siteLabelPicture = new QLabel(siteWidget);
    siteLabelPicture->setGeometry(QRect(10, 10, 455, 155));
    siteLabelPicture->setScaledContents(true);

    QPixmap picture(":/resource/images/Duxit FB picture_1.png");
    siteLabelPicture->setPixmap(picture);

    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
    connect(managementButton, SIGNAL(pressed()), this, SLOT(on_managementButton_clicked()));
    connect(serverButton, SIGNAL(pressed()), this, SLOT(on_serverButton_clicked()));
    connect(storageButton, SIGNAL(pressed()), this, SLOT(on_storageButton_clicked()));
    connect(antivirusButton, SIGNAL(pressed()), this, SLOT(on_antivirusButton_clicked()));
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

    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
    connect(FTPButton, SIGNAL(clicked(bool)), this, SLOT(on_FTPButton_clicked()));
}

void CoolWindow::createEmployeeWidget()
{
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

    connect(sashaKravchenkoButton, SIGNAL(pressed()), this, SLOT(on_sashaButton_clicked()));
    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
}

void CoolWindow::createFTPWidget()
{
    FTPWidget = new QWidget();

    FTPGroupBox = new QGroupBox(FTPWidget);
    FTPGroupBox->setGeometry(QRect(10, 180, 440, 201));

    FTPGridLayout = new QGridLayout(FTPGroupBox);
    FTPGridLayout->setSpacing(6);
    FTPGridLayout->setContentsMargins(11, 11, 11, 11);

    VPNButton = new QPushButton("Налаштування VPN для Windows");
    fakeButton = new QPushButton("Додавання мережевих дисків");
    FTPBackButton = new QPushButton("Назад");

    FTPLabelPicture = new QLabel(FTPWidget);
    FTPLabelPicture->setGeometry(QRect(10, 10, 455, 155));
    FTPLabelPicture->setScaledContents(true);

    QPixmap picture(":/resource/images/Duxit FB picture_1.png");
    FTPLabelPicture->setPixmap(picture);

    FTPGridLayout->addWidget(VPNButton, 0, 0, 1, 1);
    FTPGridLayout->addWidget(fakeButton, 1, 0, 1, 1);
    FTPGridLayout->addWidget(FTPBackButton, 2, 0, 2, 1);

    connect(VPNButton, SIGNAL(clicked(bool)), this, SLOT(on_VPNButton_clicked()));
    connect(FTPBackButton, SIGNAL(clicked(bool)), this, SLOT(on_FTPBackButton_clicked()));
}

void CoolWindow::createClientWidget()
{
    clientWidget = new QWidget();

    clientGroupBox = new QGroupBox(clientWidget);
    clientGroupBox->setGeometry(QRect(10, 10, 455, 335));

    clientGridLayout = new QGridLayout(clientWidget);
    clientGridLayout->setSpacing(6);
    clientGridLayout->setContentsMargins(11, 11, 11, 11);

    clientFTPButton = new QPushButton("FTP");
    clientGlobalButton = new QPushButton("Global");
    clientTitanButton = new QPushButton("Titan");
    clientAeroButton = new QPushButton("Aero");
    clientSpyceButton = new QPushButton("Spyce");

    backButton = new QPushButton("Назад");

    clientGridLayout->addWidget(clientFTPButton, 0, 0, 1, 1);
    clientGridLayout->addWidget(clientGlobalButton, 0, 1, 1, 1);
    clientGridLayout->addWidget(clientTitanButton, 1, 0, 1, 1);
    clientGridLayout->addWidget(clientAeroButton, 1, 1, 1, 1);
    clientGridLayout->addWidget(clientSpyceButton, 2, 0, 1, 1);
    clientGridLayout->addWidget(backButton, 3, 0, 1, 2);

    connect(clientGlobalButton, SIGNAL(clicked(bool)), this, SLOT(on_globalButtonClicked()));
    connect(backButton, SIGNAL(pressed()), this, SLOT(on_backButton_clicked()));
}

void CoolWindow::createGlobalWidget()
{
    globalWidget = new QWidget();

    globalGroupBox = new QGroupBox(globalWidget);
    globalGroupBox->setGeometry(QRect(10, 10, 455, 335));

    globalGridLayout = new QGridLayout(globalWidget);
    globalGridLayout->setSpacing(6);
    globalGridLayout->setContentsMargins(11, 11, 11, 11);

    globalAntivirusButton = new QPushButton("Антивірус");
    fileStorageButton = new QPushButton("Файлове сховище");
    networkEquipmentButton = new QPushButton("Мережеве обладнання");
    globalServerButton = new QPushButton("Сервер");
    globalBackButton = new QPushButton("Назад");

    globalGridLayout->addWidget(globalAntivirusButton, 0, 0, 1, 1);
    globalGridLayout->addWidget(fileStorageButton, 0, 1, 1, 1);
    globalGridLayout->addWidget(networkEquipmentButton, 1, 0, 1, 1);
    globalGridLayout->addWidget(globalServerButton, 1, 1, 1, 1);
    globalGridLayout->addWidget(globalBackButton, 2, 0, 1, 2);

    connect(globalBackButton, SIGNAL(clicked(bool)), this, SLOT(on_globalBackButtonClicked()));
    connect(globalAntivirusButton, SIGNAL(clicked(bool)), this, SLOT(on_globalAntivirusButtonClicked()));
    connect(fileStorageButton, SIGNAL(clicked(bool)), this, SLOT(on_fileStorageButtonClicked()));
    connect(networkEquipmentButton, SIGNAL(clicked(bool)), this, SLOT(on_networkEquipmentButtonClicked()));
    connect(globalServerButton, SIGNAL(clicked(bool)), this, SLOT(on_globalServerButtonClicked()));
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
    QMessageBox::about(this, tr("Коротка інфрмація"),
            tr("<h2>Duxit </h2>"
            "<p>Copyright &copy; 2019 Кравченко Олександр."
            "<p>З приводу всіх питань та пропозицій зв'заних з цією програмою, "
               "звертайтесь за телефоном: +38 (050) 145 95 83 "
               "або пишіть на поштову скриньку: a.kravchenko@duxit.ua"
             "<p> Дякую за користування! "));


}

void CoolWindow::on_siteButton_clicked()
{
    qDebug() << "on_siteButton_clicked";
    if (siteWidget == nullptr)
        createSiteWidget();

    setCentralWidget(siteWidget);
    centralWidget = nullptr;
}

void CoolWindow::on_helpDeskButton_clicked()
{
    qDebug() << "on_helpDeskButton_clicked";
    QDesktopServices::openUrl(QUrl("https://support.duxit.ua/issues"));

}

void CoolWindow::on_clientButton_clicked()
{
    qDebug() << "on_clientButton_clicked";
    if (clientWidget == nullptr)
        createClientWidget();

    setCentralWidget(clientWidget);
    centralWidget = siteWidget = knowledgeWidget = employeeWidget = nullptr;
}

void CoolWindow::on_employeeButton_clicked()
{
    qDebug() << "on_employeeButton_clicked()";
    if (employeeWidget == nullptr)
        createEmployeeWidget();

    setCentralWidget(employeeWidget);
    centralWidget = siteWidget = knowledgeWidget = nullptr;
}

void CoolWindow::on_knowledgeButton_clicked()
{
    qDebug() << "on_knowledgeButton_clicked()";
    if (knowledgeWidget == nullptr)
        createKnowledgeWidget();

    setCentralWidget(knowledgeWidget);
    centralWidget = siteWidget = employeeWidget = nullptr;
}

void CoolWindow::on_backButton_clicked()
{
    qDebug() << "on_backButton_clicked()";
    if (centralWidget == nullptr)
        createMainWidget();

    setCentralWidget(centralWidget);

    siteWidget = employeeWidget = knowledgeWidget = clientWidget = nullptr;
}

void CoolWindow::on_storageButton_clicked()
{
    qDebug() << "on_storageButton_clicked()";
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

void CoolWindow::on_sashaButton_clicked()
{
    qDebug() << "on_sashaButton_clicked()";
    sashaKranchenko = new EmployeeSashaKravchenko();

    sashaKranchenko->show();
}

void CoolWindow::on_FTPButton_clicked()
{
    qDebug() << "on_FTPButton_clicked()";
    if (FTPWidget == nullptr)
        createFTPWidget();

    setCentralWidget(FTPWidget);
    knowledgeWidget = nullptr;
}

void CoolWindow::on_FTPBackButton_clicked()
{
    qDebug() << "on_FTPBackButton_clicked()";
    if (knowledgeWidget == nullptr)
        createKnowledgeWidget();

    setCentralWidget(knowledgeWidget);
    FTPWidget = nullptr;
}

void CoolWindow::on_VPNButton_clicked()
{
    qDebug() << "on_VPNButton_clicked()";
    vpnForWindows = new VpnForWindows();
    vpnForWindows->show();
}

void CoolWindow::on_globalButtonClicked()
{
    qDebug() << "on_globalButtonClicked()";
    if (globalWidget == nullptr)
        createGlobalWidget();

    setCentralWidget(globalWidget);
    clientWidget = nullptr;
}

void CoolWindow::on_globalBackButtonClicked()
{
    qDebug() << "on_globalBackButtonClicked()";
    if (clientWidget == nullptr)
        createClientWidget();

    setCentralWidget(clientWidget);
    globalWidget = nullptr;
}

void CoolWindow::on_globalAntivirusButtonClicked()
{
    qDebug() << "on_globalAntivirusButtonClicked()";
    QDesktopServices::openUrl(QUrl("http://gc-era.online365.com.ua"));
}

void CoolWindow::on_fileStorageButtonClicked()
{
    qDebug() << "on_fileStorageButtonClicked()";
    QDesktopServices::openUrl(QUrl("http://dsm.gc365.com.ua:7695"));
}

void CoolWindow::on_networkEquipmentButtonClicked()
{
    qDebug() << "on_networkEquipmentButtonClicked()";
    QDesktopServices::openUrl(QUrl("https://212.90.188.54:4081/admin"));
}

void CoolWindow::on_globalServerButtonClicked()
{
    qDebug() << "on_globalServerButtonClicked()";
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath() + "/RDP/" + "GCOffice.RDP"));
//    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/pasha/Downloads/SashaDiploma/GCOffice.RDP"));
}

CoolWindow::~CoolWindow()
{

}
