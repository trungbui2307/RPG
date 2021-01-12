#include "ObjetRamassable.h"

ObjetRamassable::ObjetRamassable()
{
    //ctor
}

ObjetRamassable::ObjetRamassable(Position p, int po) : Element(p), point(po)
{
    //ctor
}


ObjetRamassable::~ObjetRamassable()
{
    //dtor
}

void ObjetRamassable::setPoint(int poi)
{
    point = poi;
}

int ObjetRamassable::getPoint()
{
    return point;
}
