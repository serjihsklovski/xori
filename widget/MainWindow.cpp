#include "MainWindow.h"
#include "domain/Source.h"
#include "Initializer.h"

#include <QDebug>


Xori::Widget::MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    Initializer::getInstance();
    Initializer::getInstance();
    Initializer::getInstance();

    QList<Domain::Source> sources = {
        Domain::Source(1, QUrl("C:/Users/Serjih/ass.txt"), "ass.txt"),
        Domain::Source(2, QUrl("C:/Users/Serjih/das.txt"), "das.txt"),
        Domain::Source(3, QUrl("C:/Users/Serjih/sas.txt"), "sas.txt")
    };

    foreach (Domain::Source source, sources) {
        qDebug() << source.getId() << source.getUrl() << source.getFileName();
    }
}


Xori::Widget::MainWindow::~MainWindow() {
}
