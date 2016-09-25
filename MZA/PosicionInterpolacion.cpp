/* 
 * File:   PosicionInterpolacion.cpp
 * Author: Marta
 * 
 * Created on 22 de abril de 2015, 18:21
 */

#include "PosicionInterpolacion.h"

PosicionInterpolacion::PosicionInterpolacion() {
    lastX = 0;
    lastY = 0;
    x=0;
    y=0;
}

PosicionInterpolacion::PosicionInterpolacion(const PosicionInterpolacion& orig) {
}

PosicionInterpolacion::~PosicionInterpolacion() {
}
void PosicionInterpolacion::setPos(float tx, float ty){
    if(x == 0 && y == 0){
        lastX = tx;
        lastY = ty;
    }else{
        lastX = x;
        lastY = y;
    }
    x = tx;
    y = ty;
}

sf::Vector2f* PosicionInterpolacion::getLastPos(){
    sf::Vector2f *vector = new sf::Vector2f(lastX,lastY);
    return vector;

}

void PosicionInterpolacion::mover(int n, int m) {
    
    if(x == 0 && y == 0){
        lastX = n;
        lastY = m;
    }else{
        lastX = x;
        lastY = y;
    }
    x += n;
    y += m;
}

sf::Vector2f* PosicionInterpolacion::getPos(){
    sf::Vector2f *vector = new sf::Vector2f(x,y);
    return vector;

}
