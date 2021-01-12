#include "Position.h"
#include <iostream>

Position::Position()
{
    //ctor
}

Position::~Position()
{
    //dtor
}

Position::Position(int a, int b) : x(a), y(b)
{
}

int Position::getX()
{
    return x;
}


void Position::setX(int a)
{
    x = a;
}

void Position::setY(int b)
{
    y = b;
}

int Position::getY()
{
    return y;
}
bool operator ==(Position a, Position b)
{
    //std::cout << "run oper" << std::endl;
    //std::cout << a.x << a.y << std::endl;
    //std::cout << b.x << b.y << "point" << std::endl;
    //std::cout << "------------------------------------------" << std::endl;
    if(a.x == b.x && a.y == b.y){
        return true;
    }else{
        return false;
    }
}
