#include "MainWindow.h"
#include "domain/Source.h"
#include "Initializer.h"

#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>

#include <QPushButton>

#include <QDebug>


Xori::Widget::MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    Initializer::getInstance();

    sourceModel = new QSqlTableModel;

    sourceModel->setTable("source");
    sourceModel->select();

    QTableView* tableView = new QTableView;

    tableView->setModel(sourceModel);
    tableView->hideColumn(0);

    //

    QWidget* widget = new QWidget;

    QVBoxLayout* layout = new QVBoxLayout;

    QPushButton* btnOpenFiles = new QPushButton("Open files");

    connect(btnOpenFiles, SIGNAL(clicked()), this, SLOT(openFiles()));

    layout->addWidget(tableView);
    layout->addWidget(btnOpenFiles);

    widget->setLayout(layout);

    setCentralWidget(widget);
}


Xori::Widget::MainWindow::~MainWindow() {
}


void Xori::Widget::MainWindow::openFiles() {
    QStringList urls = QFileDialog::getOpenFileNames();
    Domain::Source source;
    int rowCount = sourceModel->rowCount();

    for (int i = 0; i < urls.length(); i++) {
        source = Domain::Source(-1, QUrl(urls.at(i)));

        sourceModel->setEditStrategy(QSqlTableModel::OnRowChange);
        sourceModel->insertRow(sourceModel->rowCount());

        sourceModel->setData(
            sourceModel->index(rowCount + i, 1),
            source.getUrl().toString(),
            Qt::EditRole
        );

        sourceModel->setData(
            sourceModel->index(rowCount + i, 2),
            source.getFileName(),
            Qt::EditRole
        );

        if (!sourceModel->submit()) {
            qDebug() << sourceModel->lastError();
        }
    }
}
