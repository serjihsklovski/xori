#include "widget/MainWindow.h"

#include <QApplication>


int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    Xori::Widget::MainWindow xori;

    xori.show();

    return application.exec();
}
