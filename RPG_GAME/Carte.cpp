#include "Carte.h"
#include "Position.h"
#include "Guerrier.h"
#include "Obstacle.h"
#include "ObjetRamassable.h"
#include "Element.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

Carte::Carte()
{
    //ctor
}

Carte::~Carte()
{
    //dtor
}


Carte::Carte (const char *filename)
{
    loadMap(filename);
}

void Carte::ajout(Obstacle o)
{
    obs.push_back(o);
}

void Carte::ajout(ObjetRamassable objet)
{
   objRamass.push_back(objet);
}

void Carte::ajout(Guerrier g)
{
    if(g.getEq() == "team"){
        guer = g;
    }else{
        guerEnemy = g;
    }
}

// Question 7 Écrire une méthode d'affichage d'une Carte qui affichera à l'écran la carte suivant le même
//format qu'un fichier décrit.
void Carte::afficheCarte()
{
    for(int i = 0; i< largeur; i++){
        for(int j = 0; j< hauteur;j++){
            cout << mazeChar[i][j];
        }
        cout << endl;
    }

}

void Carte::afficheCarteInt()
{
    for(int i = 0; i< largeur; i++){
        for(int j = 0; j< hauteur;j++){
            cout << mazeInt[i][j] << "|";
        }
        cout << endl;
    }
}

// Load the map from texte file
void Carte::loadMap(const char*filename)
{
    std::ifstream openfile(filename);
    if(openfile.fail())
    {
        cout <<"Failed to open this file!" << endl;
    }

    string line;

    getline(openfile, line);
    stringstream lar(line);
    lar >> largeur;
    getline(openfile, line);

    stringstream hau(line);
    hau >> hauteur;
    cout << largeur << endl;
    cout << hauteur << endl;

    char x;
    for(int i = 0;i < largeur; i++){
        for(int j = 0;j<hauteur; j++){
            openfile.get(x);
            mazeChar[i][j] = x;
            mazeInt[i][j] = (int) x;
            cout << mazeInt[i][j] << "|";
        }
        cout << endl;
        openfile.ignore(numeric_limits<streamsize>::max(),'\n');
    }

     for(int i = 0;i < largeur; i++){
        for(int j = 0;j<hauteur; j++){
            if(mazeInt[i][j] == 35){
              Position p(i,j);
              ajout(Obstacle(p));
            }
           if(mazeInt[i][j] >= 49 && mazeInt[i][j] <= 57){
               int a(mazeInt[i][j] - 48);
               ajout(ObjetRamassable(Position(i,j),a));
           }
           if(mazeInt[i][j] == 83){
               ajout(Guerrier(Position(i,j), 15, 5, 100, "team"));
           }
           if(mazeInt[i][j] == 67){
               ajout(Guerrier(Position(i,j), 25, 23, 300, "enemy"));
           }
        }
     }

    openfile.close();
}

int Carte::getLargeur()
{
    return largeur;
}

int Carte::getHauteur()
{
    return hauteur;
}

vector<Obstacle> Carte::getObs()
{
    return obs;
}

vector<ObjetRamassable> Carte::getObjRamass()
{
    return objRamass;
}

Guerrier& Carte::getGuer()
{
    return guer;
}

Guerrier& Carte::getGuerEnemy()
{
    return guerEnemy;
}

// Question 8: verifier si le deplacement est possible
bool Carte::checkDeplacement(Guerrier g, Direction dir)
{
    int x = g.getP().getX();
    int y = g.getP().getY();
    switch(dir)
    {
    case LEFT:
        return (mazeInt[x][y-1] != 35 /*&& (mazeInt[x][y-1] < 49 || mazeInt[x][y-1] > 57) */&& mazeInt[x][y-1] != 67 );
        break;
    case RIGHT:
        return (mazeInt[x][y+1] != 35 /*&& (mazeInt[x][y+1] < 49 || mazeInt[x][y+1] > 57)*/ && mazeInt[x][y+1] != 67);
        break;
    case UP:
        return (mazeInt[x-1][y] != 35 /*&& (mazeInt[x-1][y] < 49 || mazeInt[x-1][y] > 57)*/ && mazeInt[x-1][y] != 67);
        break;
    case DOWN:
        return (mazeInt[x+1][y] != 35 /*&& (mazeInt[x+1][y] < 49 || mazeInt[x+1][y] > 57)*/&& mazeInt[x+1][y] != 67);
        break;
    }
}

// Question 9: effectuer le deplacement
void Carte::deplacer(Guerrier &guer, Direction dir)
{
    int x = guer.getP().getX();
    int y = guer.getP().getY();
    switch(dir)
    {
    case LEFT:
        if(checkDeplacement(guer,dir)){
            mazeInt [x][y] = 32;
            y--;
            guer.getP().setY(y);
            mazeInt[x][y] = 83;
            cout << "left" << endl;
        }
        break;
    case RIGHT:
        if(checkDeplacement(guer,dir)){
            mazeInt [x][y] = 32;
            y++;
            guer.getP().setY(y);
            mazeInt [x][y] = 83;
            cout << "right" << endl;
        }
        break;
    case UP:
        if(checkDeplacement(guer,dir)){
            mazeInt [x][y] = 32;
            x--;
            guer.getP().setX(x);
            mazeInt[x][y] = 83;
            cout << "up" << endl;
        }
        break;
    case DOWN:
        if(checkDeplacement(guer,dir)){
            mazeInt [x][y] = 32;
            x++;
            guer.getP().setX(x);
            mazeInt[x][y] = 83;
            cout << "down" << endl;
        }
        break;
    }
}

// Question 10: verifier si le guerrier peux ramasser l'objet
bool Carte::ramassable(Guerrier g)
{
    int x = g.getP().getX();
    int y = g.getP().getY();
   if(mazeInt[x+1][y] >= 49 && mazeInt[x+1][y] <= 57){
             cout << "d" << endl;
        return true;
    }
     if(mazeInt[x-1][y] >= 49 && mazeInt[x-1][y] <= 57){
             cout << "u" << endl;
        return true;
    }
     if(mazeInt[x][y+1] >= 49 && mazeInt[x][y+1] <= 57){
             cout << "r" << endl;
        return true;
    }
     if(mazeInt[x][y-1] >= 49 && mazeInt[x][y-1] <= 57){
            cout << "l" << endl;
        return true;
    }
    return false;
}

// Question 11: Ramasser
void Carte::ramasser(Guerrier &guer)
{
    int x = guer.getP().getX();
    int y = guer.getP().getY();
    Position pl(x,--y);
    int y2 = guer.getP().getY();
    Position pr(x,++y2);
    int a = guer.getP().getX();
    int b = guer.getP().getY();
    Position pu(--a,b);
    int a2 = guer.getP().getX();
    Position pd (++a2,b);
    cout << "--------------------------------" << endl;
    for(int i = 0; i < objRamass.size();i++){
        if(objRamass[i].getP() == pl || objRamass[i].getP() == pr || objRamass[i].getP() == pu || objRamass[i].getP() == pd){
            cout << objRamass[i].getP().getX() << objRamass[i].getP().getY() << endl;
            cout << "ramasser" << endl;
            guer.incPDV(objRamass[i].getPoint());
            guer.incCapaAtt(objRamass[i].getPoint()*2);
            objRamass.erase(objRamass.begin() + i);
            cout <<"pdv:" << guer.getPDV();

            break;

        }
    }
}

//Question 12 :
bool Carte::rencontreAd(Guerrier guer)
{
    int x = guer.getP().getX();
    int y = guer.getP().getY();
      if(mazeInt[x+1][y] == 67){
        return true;
    }
     if(mazeInt[x-1][y] == 67){
        return true;
    }
     if(mazeInt[x][y+1] == 67){
        return true;
    }
     if(mazeInt[x][y-1] == 67){
        return true;
    }
    return false;
}

void Carte::attaque(Guerrier &guer, Guerrier &guerEnemy, Direction dir)
{
    int x = guer.getP().getX();
    int y = guer.getP().getY();
    switch(dir){
    case DOWN:
        x++;
        if(mazeInt[x][y] == 67){
            guer.teamAtt(guerEnemy);
            guerEnemy.enemyAtt(guer);
            if(guerEnemy.getPDV() <= 0){
                mazeInt[x][y] = 32;
            }
            if(guer.getPDV() <= 0){
                mazeInt[--x][y] = 32;
            }
        }
        break;
    case UP:
        x--;
        if(mazeInt[x][y] == 67){
            guer.teamAtt(guerEnemy);
            guerEnemy.enemyAtt(guer);
            if(guerEnemy.getPDV() <= 0){
                cout << "check" << endl;
                mazeInt[x][y] = 32;
            }
            if(guer.getPDV() <= 0){
                mazeInt[++x][y] = 32;
            }
        }
        break;
    case RIGHT :
        y++;
        if(mazeInt[x][y] == 67){
            guer.teamAtt(guerEnemy);
            guerEnemy.enemyAtt(guer);
            if(guerEnemy.getPDV() <= 0){
                mazeInt[x][y] = 32;
            }
            if(guer.getPDV() <= 0){
                mazeInt[x][--y] = 32;
            }
        }
        break;
    case LEFT:
        y--;
        if(mazeInt[x][y] == 67){
            guerEnemy.enemyAtt(guer);
            guer.teamAtt(guerEnemy);
            if(guerEnemy.getPDV() <= 0){
                mazeInt[x][y] = 32;
            }
            if(guer.getPDV() <= 0){
                mazeInt[x][++y] = 32;
            }
        }
        break;
    }
}

bool Carte::brisable(int x, int y)
{
    for(int i = 1;i < (largeur - 1);i++){
        for(int j = 1; j< (hauteur -1);j++){
            if(i == x && j == y){
                return true;
            }
        }
    }
    return false;
}

void Carte::briser(Direction dir)
{
    int x = guer.getP().getX();
    int y = guer.getP().getY();
    switch(dir){
    case LEFT:
        y--;
        if(brisable(x,y) && mazeInt[x][y] == 35){
            mazeInt[x][y] = 32;
        }
        break;
    case RIGHT:
        y++;
        if(brisable(x,y) && mazeInt[x][y] == 35){
            mazeInt[x][y] = 32;
        }
        break;
    case UP:
        x--;
        if(brisable(x,y) && mazeInt[x][y] == 35){
            mazeInt[x][y] = 32;
        }
        break;
    case DOWN:
        x++;
        if(brisable(x,y) && mazeInt[x][y] ==35){
            mazeInt[x][y] = 32;
        }
        break;
    }
}



