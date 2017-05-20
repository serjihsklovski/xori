#include "XoriMainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QTextEdit>
#include <QLabel>
#include <QSplitter>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTabWidget>


XoriMainWindow::XoriMainWindow(QWidget* parent) : QMainWindow(parent) {
    initXoriMenu();

    QWidget* widget = new QWidget;

    QSplitter* splitter = new QSplitter(Qt::Horizontal);

    QTreeWidget* treeWidget = new QTreeWidget;
    QTabWidget* tabWidget = new QTabWidget;

    // tabs
    QTextEdit* textEdit = new QTextEdit;

    textEdit->setFont(QFont("consolas", 11));

    tabWidget->addTab(textEdit, "test");
    tabWidget->setTabsClosable(true);

    splitter->addWidget(treeWidget);
    splitter->addWidget(tabWidget);


    QVBoxLayout* vBoxLayout = new QVBoxLayout;

    vBoxLayout->addWidget(splitter);

    widget->setLayout(vBoxLayout);

    setCentralWidget(widget);
}


XoriMainWindow::~XoriMainWindow() {
}



void XoriMainWindow::initXoriMenu() {
    QMenuBar* menuBar = new QMenuBar;

    QMenu* menuFile = new QMenu("&File");
    QMenu* menuEdit = new QMenu("&Edit");
    QMenu* menuReference = new QMenu("&Reference");

    // File menu
    menuFile->addAction("New");
    menuFile->addAction("Open");
    menuFile->addAction("Save");
    menuFile->addAction("Save as...");
    menuFile->addSeparator();
    menuFile->addAction("Quit");

    // Edit menu
    menuEdit->addAction("Undo");
    menuEdit->addAction("Redo");
    menuEdit->addSeparator();
    menuEdit->addAction("Copy");
    menuEdit->addAction("Cut");
    menuEdit->addAction("Paste");

    // Reference menu
    menuReference->addAction("About");

    menuBar->addMenu(menuFile);
    menuBar->addMenu(menuEdit);
    menuBar->addMenu(menuReference);

    setMenuBar(menuBar);
}
