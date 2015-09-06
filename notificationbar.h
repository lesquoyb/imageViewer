#ifndef NOTIFICATIONBAR_H
#define NOTIFICATIONBAR_H

#include <QWidget>

namespace Ui {
class NotificationBar;
}

class NotificationBar : public QWidget {
    Q_OBJECT

public:
    explicit NotificationBar(QWidget *parent = 0);
    void notify(const QString &message);
    ~NotificationBar();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::NotificationBar *ui;
};

#endif // NOTIFICATIONBAR_H
