#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H
#include <QGraphicsView>
#include <QKeyEvent>


class ImageView : public QGraphicsView {

    void zoomIn();
    void zoomOut();
    void left();
    void right();
    void up();
    void down();


public:
    ImageView();
    ImageView(QWidget*&w):QGraphicsView(w){}
    ~ImageView();
    void keyPressEvent(QKeyEvent* k);

};

#endif // IMAGEVIEW_H
