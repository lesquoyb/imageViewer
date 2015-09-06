#include "imageview.h"


ImageView::ImageView(){

}

ImageView::~ImageView(){

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














