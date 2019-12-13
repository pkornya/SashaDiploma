#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//namespace Ui {
//class MainWindow;
//}

#include <employeesashakravchenko.h>

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

public slots:
    void fileNew();
    void print();
    void about();

    void on_siteButton_clicked();
    void on_helpDeskButton_clicked();
    void on_clientButton_clicked();
    void on_employeeButton_clicked();
    void on_knowledgeButton_clicked();

    void on_backButton_clicked();
    void on_storageButton_clicked();
    void on_managementButton_clicked();
    void on_serverButton_clicked();
    void on_antivirusButton_clicked();

    void on_sashaButton_clicked();

    void on_FTPButton_clicked();

private:
    QMenu       *menu;

    QAction     *newAction;
    QAction     *printAction;
    QAction     *closeAction;
    QAction     *exitAction;
    QAction     *aboutQtAction;

    QWidget     *siteWidget = nullptr;
    QPushButton *backButton;
    QPushButton *managementButton;
    QPushButton *serverButton;
    QPushButton *storageButton;
    QPushButton *antivirusButton;
    QGridLayout *siteGridLayout;
    QGroupBox   *siteGroupBox;

    QWidget     *centralWidget = nullptr;
    QPushButton *clientButton;
    QPushButton *siteButton;
    QPushButton *knowledgeButton;
    QPushButton *employeeButton;
    QPushButton *helpDeskButton;
    QGroupBox   *centralGroupBox;
    QGridLayout *centralGridLayout;
    QLabel      *centralLabelPicture;

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


    QWidget     *knowledgeWidget = nullptr;
    QGroupBox   *knowledgeGroupBox;
    QGridLayout *knowledgeGridLayout;

    QPushButton *FTPButton;
    QPushButton *globalButton;
    QPushButton *titanButton;
    QPushButton *aeroButton;
    QPushButton *spyceButton;

//    FTP
//    Global
//    Titan
//    Aero
//    Spyce

    QWidget     *FTPWidget = nullptr;
    QGroupBox   *FTPGroupBox;
    QGridLayout *FTPGridLayout;

    QPushButton *VPNButton;
    QPushButton *fakeButton;


};

#endif // MAINWINDOW_H
