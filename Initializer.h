#ifndef XORI_INITIALIZER_H
#define XORI_INITIALIZER_H


#include "Xori.h"


class Xori::Initializer {

    private:
        Initializer();


    public:
        static Initializer getInstance();


    private:
        static bool hasInstance;
        static Initializer instance;
};


#endif // XORI_INITIALIZER_H
