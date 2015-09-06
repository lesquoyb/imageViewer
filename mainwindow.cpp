#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete watcher;
    delete image;
    delete item;
    delete scene;
}


void MainWindow::open(const QString &path){

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addItem(new QGraphicsTextItem("coucou"));
    load(path);
    listen(path);
    ui->graphicsView->show();
}


void MainWindow::listen(const QString &path){
    watcher = new QFileSystemWatcher;
    watcher->addPath(path);
    QObject::connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(load(const QString &)));

}

void MainWindow::load(const QString &path){

    image = new QPixmap();
    image->load(path);
    if( ! image->isNull()){
        item = new QGraphicsPixmapItem();
        item->setPixmap(*image);
        item->setFlag(QGraphicsItem::ItemIsMovable);
        scene->addItem(item);
    }

}
