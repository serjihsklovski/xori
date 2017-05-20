#ifndef XORI_WIDGET_MAINWINDOW_H
#define XORI_WIDGET_MAINWINDOW_H


#include "Xori.h"

#include <QMainWindow>


class Xori::Widget::MainWindow : public QMainWindow {

        Q_OBJECT


    public:
        explicit MainWindow(QWidget* parent = 0);
        ~MainWindow();
};


#endif // XORI_WIDGET_MAINWINDOW_H
