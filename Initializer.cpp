#include "Initializer.h"

#include <QDebug>


bool Xori::Initializer::hasInstance = false;


Xori::Initializer::Initializer() {
    hasInstance = true;

    createFolders();
    createConnection();

    qDebug() << "Initialized";
}


Xori::Initializer Xori::Initializer::getInstance() {
    if (hasInstance) {
        return instance;
    }

    return Initializer();
}
