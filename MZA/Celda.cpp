/* 
 * File:   Celda.cpp
 * Author: Alex
 * 
 * Created on 27 de abril de 2015, 18:51
 * 
 */

#include "Celda.h"

Celda::Celda() {
}

Celda::Celda(sf::Vector2i po, int gp, int hp, int fp, Celda *p){
    pos=po;
    g=gp;
    h=hp;
    f=fp;
    padre=p;
}

Celda::Celda(const Celda& orig) {
}

Celda::~Celda() {
}
void Celda::setG(int a){
    g=a;
}
int Celda::getG(){
    return g;
}
void Celda::setH(int a){
    h=a;
}
int Celda::getH(){
    return h;
}
void Celda::setF(int a){
    f=a;
}
int Celda::getF(){
    return f;
}
void Celda::setPos(int xx, int yy){
    pos.x=xx;
    pos.y=yy;
}
sf::Vector2i Celda::getPos(){
    return pos;
}
void Celda::setpadre(Celda p){
    padre=&p;
}
Celda* Celda::getPadre(){
    return padre;
}
