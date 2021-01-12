#ifndef GUERRIER_H
#define GUERRIER_H
#include <string>
#include "Element.h"

class Guerrier : public Element
{
    public:
        Guerrier();
        Guerrier(Position, int, int, int, std::string);
        virtual ~Guerrier();

        int getPDV();
        int getCA();
        int getCD();
        std::string getEq();

        void incPDV(int);
        void incCapaAtt(int);

        bool estAdversaire(Guerrier);

        void enemyAtt(Guerrier&);
        void teamAtt(Guerrier&);


    protected:

    private:
        int point_de_vie = 100;
        std::string equipe;
        std::string nom;
        int capaAtt;
        int capaDef;
};

#endif // GUERRIER_H
