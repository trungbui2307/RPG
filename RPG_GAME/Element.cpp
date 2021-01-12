#include<iostream>
#include "Element.h"
#include "Position.h"

Element::Element()
{
    //ctor
}

Element::Element(Position p) : pos(p)
{
}

Element::~Element()
{
    //dtor
}

Position& Element::getP()
{
    return pos;
}

void Element::setP(Position p)
{
    pos = p;
}
