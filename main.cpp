#include <QApplication>
#include "imageview.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageView* w = new ImageView();
    if(argc == 2){
        w->openNewFile(argv[1]);
    }
    w->show();

    return a.exec();
}
