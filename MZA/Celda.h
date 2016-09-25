/* 
 * File:   Celda.h
 * Author: Alex
 *
 * Created on 27 de abril de 2015, 18:51
 */

#include <SFML/Graphics.hpp>
#ifndef CELDA_H
#define	CELDA_H

class Celda {
public:
    Celda();
    Celda(sf::Vector2i po, int gp, int hp, int fp, Celda *p);
    Celda(const Celda& orig);
    virtual ~Celda();
    void setG(int a);
    int getG();
    void setH(int a);
    int getH();
    void setF(int a);
    int getF();
    void setPos(int x, int y);
    sf::Vector2i getPos();
    void setpadre(Celda p);
    Celda* getPadre();
private:
    sf::Vector2i pos;
    int g;
    int h;
    int f;
    Celda* padre;

};

#endif