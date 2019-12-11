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

private:
//    QMenu       *menu;

    QAction     *newAction;
    QAction     *printAction;
    QAction     *closeAction;
    QAction     *exitAction;
    QAction     *aboutQtAction;


    QPushButton *back_button;
    QPushButton *forward_button;
    QWidget *window = nullptr;
    QPushButton *management_button;
    QPushButton *server_button;
    QPushButton *storage_button;
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
    QMenuBar *menuBar;

};

#endif // MAINWINDOW_H
