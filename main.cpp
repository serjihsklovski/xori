#include "XoriMainWindow.h"
#include <QApplication>


int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    XoriMainWindow xori;

    xori.showMaximized();

    return application.exec();
}
