#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QPushButton;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void createMenus();

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
    QMenu       *menu;

    QAction     *newAction;
    QAction     *printAction;
    QAction     *closeAction;
    QAction     *exitAction;
    QAction     *aboutQtAction;

    Ui::MainWindow *ui;

    QPushButton *back_button;
    QWidget *window;
    QPushButton *management_button;
    QPushButton *server_button;
    QPushButton *storage_button;
    QHBoxLayout *layout;
};

#endif // MAINWINDOW_H
