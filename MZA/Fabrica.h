/* 
 * File:   Fabrica.h
 * Author: Marta
 *
 * Created on 22 de abril de 2015, 17:11
 */

#ifndef FABRICA_H
#define	FABRICA_H
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Estructura.h"
#include "Castillo.h"
#include "Boton.h"
#include "Arquero.h"
#include "Canon.h"
#include "Mina.h"
#include "Muro.h"
#include "Mapa.h"
#include "Jugador.h"

using namespace std;
class Fabrica {
public:
    static Fabrica* Instance();
    void update(float transcurrido,bool onClick,sf::Vector2i raton);
    void render(sf::RenderWindow &window, float percenTick);
    Estructura* getCastillo();
    
    Estructura* getEstructura(int i);
    void construirEstructura(int tipo, int x, int y);
    void destruirEstructura(Estructura* s);
    void destroyAll();
    void cambiarMostrarElementosEstructura(bool n);
    void cambiarEstaEnBoton(bool n);
    bool getEstaEnBoton();
    Jugador* getJugador();
    vector<Estructura*> getVector();
    Estructura* getEstructuraHover(int x, int y); 
protected:
    Fabrica();
    Fabrica(const Fabrica& orig);
    virtual ~Fabrica();
private:
    static Fabrica* pinstance;
    sf::Text castilloNivel;
    sf::Sprite castilloVida;
    Jugador* jugador;
    
    vector<Estructura*> estructuras;
    bool mostrarElementosEstructura;
    bool estaEnBoton;
};

#endif	/* FABRICA_H */

