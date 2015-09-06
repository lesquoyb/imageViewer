#include "imageview.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QFileDialog>

ImageView::ImageView()
    :QGraphicsView()
{
    image = NULL;
    watcher = NULL;
    item = NULL;
    createShortcuts();
    fileName = "";
    notifBar = new NotificationBar(this);
    scene = new QGraphicsScene();
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

ImageView::~ImageView()
{
    delete watcher;
    delete item;
    delete image;
    delete notifBar;
    delete scene;

    delete opShort;
    delete fitShort;
}


void ImageView::createShortcuts(){
    opShort = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this, SLOT(open()));
    fitShort = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_F), this, SLOT(fitToImage()));
}


void ImageView::fitToImage(){
    if(image != NULL && ! image->isNull()){
        this->resize(image->width()+2,image->height()+2);
         scene->setSceneRect(item->mapRectToScene(0,0,image->width(),image->height()));
    }
}


void ImageView::open(){

    QString path = QFileDialog::getOpenFileName(this,"select an image");
    openNewFile(path);
}

void ImageView::openNewFile(const QString &path){

    load(path);
    listen(path);
    updateTitle();
}


void ImageView::updateTitle(){
    setWindowTitle("Simple Image Viewer: " + fileName);
}

void ImageView::load(const QString &path){
    //TODO: pourquoi c'est appellé 2 fois ?
    delete image;
    image = new QPixmap();
    image->load(path);
    if( ! image->isNull()){
        fileName = QFileInfo(path).fileName();//I know it's overkill but I'm lazy
        notifBar->hide();
        delete item;
        item = new QGraphicsPixmapItem();
        item->setPixmap(*image);
        item->setFlag(QGraphicsItem::ItemIsMovable);
        scene->clear();
        scene->addItem(item);
    }
    else{
        notify("invalid path: " + path);
    }

}


void ImageView::notify(const QString &message){
    notifBar->notify(message);
}


void ImageView::listen(const QString &path){
    delete watcher;
    watcher = new QFileSystemWatcher;
    watcher->addPath(path);
    ImageView::connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(load(const QString &)));

}





void ImageView::keyPressEvent(QKeyEvent* k){
    switch(k->key()){
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;

        //TODO: touches perso modifiables
        /*
    case Qt::Key_Right:
        right();
        break;

    case Qt::Key_Left:
        left();
        break;

    case Qt::Key_Up:
        up();
        break;

    case Qt::Key_Down:
        down();
        break;
        */
    }
    QGraphicsView::keyPressEvent(k);
}


void ImageView::zoomIn(){
    scale(1.25,1.25);
}

void ImageView::zoomOut(){
    scale(0.75,0.75);
}

void ImageView::right(){

}

void ImageView::left(){

}

void ImageView::up(){

}

void ImageView::down(){

}














