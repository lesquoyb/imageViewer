#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileSystemWatcher>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{

    Q_OBJECT

    QGraphicsScene* scene;

    void listen(const QString &path);
    QGraphicsPixmapItem* item ;
    QPixmap* image ;
    QFileSystemWatcher* watcher;
public:

    void open(const QString &path);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void load(const QString &path);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
