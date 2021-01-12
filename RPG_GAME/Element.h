#ifndef ELEMENT_H
#define ELEMENT_H
#include "Position.h"


class Element
{
    public:
        Element();
        Element(Position);
        virtual ~Element();
        Position& getP();
        void setP(Position);

    protected:

    private:
        Position pos;
};

#endif // ELEMENT_H
