#ifndef CARTE_H
#define CARTE_H
#include "Guerrier.h"
#include "Obstacle.h"
#include "ObjetRamassable.h"
#include "Element.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Carte
{
    public:
        int mazeInt[100][100];

        enum Direction{ LEFT, RIGHT, UP, DOWN} dir;
        Carte();
        Carte(const char *filename);
        virtual ~Carte();

        void ajout(Obstacle);
        void ajout(ObjetRamassable);
        void ajout(Guerrier);
        //Afficher carte au meme format de la ficher
        void afficheCarte();
        void afficheCarteInt();
        void loadMap(const char*filename);
        //Accesseurs
        int getLargeur();
        int getHauteur();
        vector<Obstacle> getObs();
        vector<ObjetRamassable> getObjRamass();
        Guerrier& getGuer();
        Guerrier& getGuerEnemy();

        bool checkDeplacement(Guerrier, Direction);
        void deplacer(Guerrier&, Direction);

        bool ramassable(Guerrier);
        void ramasser(Guerrier&);

        bool rencontreAd(Guerrier);
        void attaque(Guerrier&, Guerrier&, Direction);

        bool brisable(int , int);
        void briser(Direction);

    protected:

    private:
        int largeur;
        int hauteur;
        vector<Obstacle> obs;
        vector<ObjetRamassable> objRamass;
        Guerrier guer;
        Guerrier guerEnemy;
        char mazeChar [100][100];


};

#endif // CARTE_H
