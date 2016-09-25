/* 
 * File:   Mina.h
 * Author: Marta
 *
 * Created on 23 de abril de 2015, 21:00
 */

#include "Estructura.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef MINA_H
#define	MINA_H
using namespace std;
class Mina : public Estructura{
    
private:
    int minaGeneracionOro;
    sf::Clock reloj;
    sf::Sprite oroSprite;
    sf::Texture oroTexture;
    int oro;
    PosicionInterpolacion* posicionOro;
    
    
public:
    Mina();
    Mina(const Mina& orig);
    virtual ~Mina();
    void actualizarMina(float transcurrido,bool onClick,sf::Vector2i raton);
    void renderMina(sf::RenderWindow &window,float tick);
    void posicionaOro();
    void aumentarNivelMina(int n);
    void quitarVidaMina();
    void mostrarInfoMina();
    void generarOro();
    void repararMina();
    void setMinaGeneracionOro(int g);
    int getMinaGeneracionOro();
};

#endif	/* MINA_H */
