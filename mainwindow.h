#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//namespace Ui {
//class MainWindow;
//}

#include <employeesashakravchenko.h>
#include <vpnforwindows.h>

class QPushButton;
class QHBoxLayout;
class QLabel;
class QGroupBox;
class QGridLayout;
class QListWidget;

class CoolWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoolWindow(QWidget *parent = 0);
    ~CoolWindow();

private:
    void createActions();
    void createMenus();

    void createSiteWidget();
    void createMainWidget();
    void createKnowledgeWidget();
    void createEmployeeWidget();
    void createFTPWidget();
    void createClientWidget();
    void createGlobalWidget();

public slots:
    void fileNew();
    void print();
    void about();

    // slots for cental widget
    void on_siteButton_clicked();
    void on_helpDeskButton_clicked();
    void on_clientButton_clicked();
    void on_employeeButton_clicked();
    void on_knowledgeButton_clicked();

    // slots for site widget
    void on_backButton_clicked();
    void on_storageButton_clicked();
    void on_managementButton_clicked();
    void on_serverButton_clicked();
    void on_antivirusButton_clicked();

    // slots for employee widget
    void on_sashaButton_clicked();

    // slots for knowledge widget
    void on_FTPButton_clicked();

    // slots for FTP widget
    void on_VPNButton_clicked();
    void on_FTPBackButton_clicked();

    // slots for client widget
    void on_globalButtonClicked();

    // slots for global widget
    void on_globalBackButtonClicked();
    void on_globalAntivirusButtonClicked();
    void on_fileStorageButtonClicked();
    void on_networkEquipmentButtonClicked();
    void on_globalServerButtonClicked();

private:
    QMenu       *menu;

    QAction     *newAction;
    QAction     *printAction;
    QAction     *closeAction;
    QAction     *exitAction;
    QAction     *aboutQtAction;

    // siteWidget
    QWidget     *siteWidget = nullptr;
    QPushButton *backButton;
    QPushButton *managementButton;
    QPushButton *serverButton;
    QPushButton *storageButton;
    QPushButton *antivirusButton;
    QGridLayout *siteGridLayout;
    QGroupBox   *siteGroupBox;
    QLabel      *siteLabelPicture;

    // centralWidget
    QWidget     *centralWidget = nullptr;
    QPushButton *clientButton;
    QPushButton *siteButton;
    QPushButton *knowledgeButton;
    QPushButton *employeeButton;
    QPushButton *helpDeskButton;
    QGroupBox   *centralGroupBox;
    QGridLayout *centralGridLayout;
    QLabel      *centralLabelPicture;

    // employeeWidget
    QWidget     *employeeWidget = nullptr;
    QGroupBox   *employeeGroupBox;
    QGridLayout *employeeGridLayout;
    QListWidget *employeeListWidget = nullptr;

    QPushButton *sashaKravchenkoButton;
    QPushButton *sashaKavraskyyButton;
    QPushButton *sashaArtemchukButton;
    QPushButton *igorGorbButton;
    QPushButton *sevastianKovalenkoButton;
    QPushButton *nataliaRiabaButton;
    QPushButton *vladislavSerdechnyyButton;
    QPushButton *evgeniaTygauKravchenkoButton;

    EmployeeSashaKravchenko* sashaKranchenko;

    // knowledgeWidget
    QWidget     *knowledgeWidget = nullptr;
    QGroupBox   *knowledgeGroupBox;
    QGridLayout *knowledgeGridLayout;

    QPushButton *FTPButton;
    QPushButton *globalButton;
    QPushButton *titanButton;
    QPushButton *aeroButton;
    QPushButton *spyceButton;

    QWidget     *FTPWidget = nullptr;
    QGroupBox   *FTPGroupBox;
    QGridLayout *FTPGridLayout;

    QPushButton *VPNButton;
    QPushButton *fakeButton;
    QPushButton *FTPBackButton;
    QLabel      *FTPLabelPicture;

    VpnForWindows* vpnForWindows;

    // clientWidget
    QWidget     *clientWidget = nullptr;
    QGroupBox   *clientGroupBox;
    QGridLayout *clientGridLayout;

    QPushButton *clientFTPButton;
    QPushButton *clientGlobalButton;
    QPushButton *clientTitanButton;
    QPushButton *clientAeroButton;
    QPushButton *clientSpyceButton;

    QWidget     *globalWidget;
    QGroupBox   *globalGroupBox;
    QGridLayout *globalGridLayout;

    QPushButton *globalAntivirusButton;
    QPushButton *fileStorageButton;
    QPushButton *networkEquipmentButton;
    QPushButton *globalServerButton;
    QPushButton *globalBackButton;

};

#endif // MAINWINDOW_H
