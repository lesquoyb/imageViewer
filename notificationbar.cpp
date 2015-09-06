#include "notificationbar.h"
#include "ui_notificationbar.h"

NotificationBar::NotificationBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationBar)
{
    ui->setupUi(this);
    hide();
}

NotificationBar::~NotificationBar()
{
    delete ui;
}


void NotificationBar::notify(const QString &message){
    ui->notifLbl->setText(message);
    this->show();
}

void NotificationBar::on_closeBtn_clicked()
{
    this->hide();
}
