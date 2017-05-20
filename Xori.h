#ifndef XORI_H
#define XORI_H


namespace Xori {

    namespace Widget {

        class MainWindow;
    }


    namespace Domain {

        class Source;
    }


    class Initializer;


    void createFolders();
    bool createConnection();
    bool createTableSource(bool createMode = false);
}


#endif // XORI_H
