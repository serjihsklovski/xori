#include "Xori.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>

#include <QDebug>


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


bool Xori::createTableSource(bool createMode) {
    QString sqlDropTable = "DROP TABLE IF EXISTS `source`";

    QString sqlCreateTable = "CREATE TABLE IF NOT EXISTS `source` ("
                             "`id` Integer PRIMARY KEY AUTOINCREMENT, "
                             "`url` VARCHAR(512) UNIQUE, "
                             "`file_name` VARCHAR(256)"
                             ")";

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    bool ok = true;

    if (createMode) {
        if (!(ok = query.exec(sqlDropTable))) {
            qDebug() << query.lastQuery();
            qDebug() << query.lastError();

            return ok;
        }
    }

    if (!(ok = query.exec(sqlCreateTable))) {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();

        return ok;
    }

    return ok;
}
