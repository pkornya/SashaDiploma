#ifndef EMPLOYEESASHAKRAVCHENKO_H
#define EMPLOYEESASHAKRAVCHENKO_H


#include <QDialog>
#include "ui_employeesashakravchenko.h"

class EmployeeSashaKravchenko : public QDialog, public Ui::EmployeeSashaKravchenko
{
    Q_OBJECT

public:
    EmployeeSashaKravchenko(QWidget *parent = 0) : QDialog(parent) { setupUi(this); }
};


#endif // EMPLOYEESASHAKRAVCHENKO_H

