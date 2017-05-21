#ifndef XORI_WIDGET_MAINWINDOW_H
#define XORI_WIDGET_MAINWINDOW_H


#include "Xori.h"

#include <QMainWindow>
#include <QSqlTableModel>


class Xori::Widget::MainWindow : public QMainWindow {

        Q_OBJECT


    public:
        explicit MainWindow(QWidget* parent = 0);
        ~MainWindow();


    public slots:
        void openFiles();


    private:
        QSqlTableModel* sourceModel;
};


#endif // XORI_WIDGET_MAINWINDOW_H
