/* 
 * File:   ZombiePrueba.cpp
 * Author: Alex
 * 
 * Created on 26 de abril de 2015, 13:08
 */

#include "ZombiePrueba.h"

ZombiePrueba::ZombiePrueba() {
}

ZombiePrueba::ZombiePrueba(const ZombiePrueba& orig) {
}

ZombiePrueba::~ZombiePrueba() {
}
int ZombiePrueba::getPosY() {
    return posX;
}
int ZombiePrueba::getPosX() {
    return posY;
}
void ZombiePrueba::setPosY(int pos) {
    posX=pos;
}
void ZombiePrueba::setPosX(int pos) {
    posY=pos;
}

int ZombiePrueba::getCeldaPosY() {
    return celdaPosX;
}
int ZombiePrueba::getCeldaPosX() {
    return celdaPosY;
}
void ZombiePrueba::setCeldaPosY(int pos) {
    celdaPosX=pos;
}
void ZombiePrueba::setCeldaPosX(int pos) {
    celdaPosY=pos;
}

sf::Vector2i ZombiePrueba::getIANextMov(){
    sf::Vector2i next;
    return next;
}
