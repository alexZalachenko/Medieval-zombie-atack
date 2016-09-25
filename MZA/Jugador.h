/* 
 * File:   Jugador.h
 * Author: Marta
 *
 * Created on 27 de abril de 2015, 18:04
 */


#ifndef JUGADOR_H
#define	JUGADOR_H
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <stdlib.h>
#include "PosicionInterpolacion.h"
using namespace std;
class Jugador {
public:
    Jugador();
    Jugador(const Jugador& orig);
    virtual ~Jugador();
    void mostrarOro(sf::RenderWindow& window);
    void quitarOro(int n);
    void darOro(int n);
    int getOro();
    void sumarPuntuacion(int n);
    int mostrarPuntuacion(sf::RenderWindow& window);
private:
    PosicionInterpolacion* posicionSpriteEstructura;
    int jugadorPuntuacion;
    int jugadorOro;
    sf::Font font;
    std::stringstream jugadorOroSS;
    sf::String jugadorOroString;
    sf::Text jugadorOroText;
    std::stringstream jugadorPuntoSS;
    sf::String jugadorPuntoString;
    sf::Text jugadorPuntoText;
    
};

#endif	/* JUGADOR_H */


