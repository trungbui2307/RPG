#include "Guerrier.h"
#include <iostream>
Guerrier::Guerrier()
{
    //ctor
}

Guerrier::Guerrier(Position p,int ca, int cd, int pdv, std::string eq) : Element(p), capaAtt(ca),capaDef(cd), point_de_vie(pdv), equipe(eq)
{
    //ctor
}

Guerrier::~Guerrier()
{
    //dtor
}

int Guerrier::getPDV()
{
    return point_de_vie;
}

int Guerrier::getCA()
{
    return capaAtt;
}

int Guerrier::getCD()
{
    return capaDef;
}

std::string Guerrier::getEq()
{
    return equipe;
}

void Guerrier::incPDV(int pdv)
{
    point_de_vie += pdv;
}

void Guerrier::incCapaAtt(int ca)
{
    capaAtt += ca;
}


bool Guerrier::estAdversaire(Guerrier g)
{
    if(g.equipe == equipe){
        return true;
    }else{
        return false;
    }
}

void Guerrier::teamAtt(Guerrier& enemy)
{

    enemy.point_de_vie += enemy.capaDef;
    enemy.point_de_vie -= capaAtt;
    std::cout<< "enemyPDV:" << enemy.point_de_vie << std::endl;

}

void Guerrier::enemyAtt(Guerrier& team)
{

    team.point_de_vie += team.capaDef;
    team.point_de_vie -= capaAtt;
    std::cout<< "teamPDV:"  << team.point_de_vie << std::endl;

}
