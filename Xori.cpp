#include "Xori.h"

#include <QSqlDatabase>
#include <QDir>


void Xori::createFolders() {
    if (!QDir("../xori/data").exists()) {
        QDir().mkdir("../xori/data");
    }
}


bool Xori::createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("../xori/data/xori.db");

    return db.open();
}
