/* 
 * File:   PosicionInterpolacion.h
 * Author: Marta
 *
 * Created on 22 de abril de 2015, 18:21
 */
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef POSICIONINTERPOLACION_H
#define	POSICIONINTERPOLACION_H

class PosicionInterpolacion {
public:
    PosicionInterpolacion();
    PosicionInterpolacion(const PosicionInterpolacion& orig);
    void setPos(float tx, float ty);
    void mover(int n, int m);
    sf::Vector2f* getLastPos();
    sf::Vector2f* getPos();
    virtual ~PosicionInterpolacion();
private:
    float x;
    float y;
    float lastX;
    float lastY;
};

#endif	/* POSICIONINTERPOLACION_H */

