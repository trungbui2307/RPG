#ifndef OBJETRAMASSABLE_H
#define OBJETRAMASSABLE_H
#include "Element.h"

class ObjetRamassable : public Element
{
    public:
        ObjetRamassable();
        ObjetRamassable(Position,int);
        void setPoint(int);
        int getPoint();
        virtual ~ObjetRamassable();

    protected:

    private:
        int point;
};

#endif // OBJETRAMASSABLE_H
