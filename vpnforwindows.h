#ifndef VPNFORWINDOWS_H
#define VPNFORWINDOWS_H

#include <QDialog>
#include "ui_vpnforwindows.h"

class VpnForWindows : public QDialog, public Ui::FTPDialog
{
    Q_OBJECT

public:
    VpnForWindows(QWidget *parent = 0) : QDialog(parent) { setupUi(this); }
};


#endif // VPNFORWINDOWS_H
