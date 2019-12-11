#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//namespace Ui {
//class MainWindow;
//}

class QPushButton;
class QHBoxLayout;
class QLabel;
class QGroupBox;
class QGridLayout;

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

private:
    QMenu       *menu;

    QAction     *newAction;
    QAction     *printAction;
    QAction     *closeAction;
    QAction     *exitAction;
    QAction     *aboutQtAction;


    QWidget     *window = nullptr;

    QPushButton *back_button;
    QPushButton *management_button;
    QPushButton *server_button;
    QPushButton *storage_button;
    QPushButton *antivirus_button;

    QGridLayout *layout;
    QGroupBox* siteGroupBox;



    QWidget *centralWidget = nullptr;
    QLabel *label_picture;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *clientButton;
    QPushButton *siteButton;
    QPushButton *knowledgeButton;
    QPushButton *employeeButton;
    QPushButton *helpDeskButton;
};

#endif // MAINWINDOW_H
