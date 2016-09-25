/* 
 * File:   ZombiePrueba.h
 * Author: Alex
 *
 * Created on 26 de abril de 2015, 13:08
 */

#ifndef ZOMBIEPRUEBA_H
#define	ZOMBIEPRUEBA_H
#include <SFML/Graphics.hpp>

class ZombiePrueba {
public:
    ZombiePrueba();
    ZombiePrueba(const ZombiePrueba& orig);
    virtual ~ZombiePrueba();
    int getPosX();//COORDENADAS PIXEL
    int getPosY();//COORDENADAS PIXEL
    void setPosX(int pos);//COORDENADAS PIXEL
    void setPosY(int pos);//COORDENADAS PIXEL
    
    int getCeldaPosX();//COORDENADAS CELDA
    int getCeldaPosY();//COORDENADAS CELDA
    void setCeldaPosX(int pos);//COORDENADAS CELDA
    void setCeldaPosY(int pos);//COORDENADAS CELDA
    sf::Vector2i getIANextMov();
private:
    int posX;
    int posY;
    
    int celdaPosX;
    int celdaPosY;

};

#endif	/* ZOMBIEPRUEBA_H */

