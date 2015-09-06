#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H
#include <QGraphicsView>
#include <QKeyEvent>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileSystemWatcher>
#include "notificationbar.h"
#include <string>
#include <QShortcut>





class ImageView : public QGraphicsView {

Q_OBJECT

public slots:
    void load(const QString &path);
    void fitToImage();
    void open();


public:

    void openNewFile(const QString &path);
    ImageView();
    ~ImageView();
    void keyPressEvent(QKeyEvent* k);



private:

    QGraphicsScene* scene;
    NotificationBar* notifBar;
    QGraphicsPixmapItem* item ;
    QPixmap* image ;
    QFileSystemWatcher* watcher;
    QString fileName;

    QShortcut* opShort;
    QShortcut* fitShort;

    void listen(const QString &path);
    void notify(const QString &message);
    void updateTitle();
    void createShortcuts();
    void zoomIn();
    void zoomOut();
    void left();
    void right();
    void up();
    void down();



};

#endif // IMAGEVIEW_H
