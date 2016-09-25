/* 
 * File:   Zombi.h
 * Author: 7w
 *
 * Created on 19 de marzo de 2015, 19:47
 */

#ifndef ZOMBI_H
#define	ZOMBI_H

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "PosicionInterpolacion.h"
#include "IAZombi.h"
#include "Estructura.h"
#include "Fabrica.h"

class Zombi {
public:
    
    Zombi();
	
    // GET
    int getPosicion();// posicion del sprite a cargar, sirve para la direccion del zombi
    int getVida();
    int getAtaque();
    float getPosX();
    float getPosY();
    float getWidth();// anchura del sprite
    float getHeight();// altura del sprite
    float getVelocidad();
    sf::Sprite getSprite();//alex
	
    // SET
    void setVida(int n);
    void setPosicion(float x, float y);
    void setVelocidad(int n);
    void setAtaque(int n);

    // OTROS
    void crearZombi(int num, bool especial, float x, float y);
    void caminar(int direccion);
    void caminarDiagonal(int diagonal);
    void cambiar();
    void atacar();
    void dibujar(sf::RenderWindow& ventana, float percenTick);
    void calcularValores(int n, bool especial);
    void calculaIA();//alex
    
private:

    IAZombi* ia;//alex
    int vida;
    int ataque;
    float velocidad;
    int posicion;
    int numOleada;
    int contador;// para cambiar de sprite
    sf::Texture textura;
    sf::Texture textAtack;
    sf::Sprite zombi;
    sf::Vector2i source;// con este vector cargamos los diferentes sprites segun la direccion
                        // la posicion Y carga la fila de la textura para la direccion del zombi
                        // la posicion X carga dentro de la fila los diferentes sprites
                        // Y=0, zombi camina hacia arriba
                        // Y=1, zombi camina hacia abajo
                        // Y=2, zombi camina hacia la derecha
                        // Y=3, zombi camina hacia la izquierda
                        // Y=4, zombi camina hacia diagonal abajo izquierda
                        // Y=5, zombi camina hacia diagonal abajo derecha
                        // Y=6, zombi camina hacia diagonal arriba izquierda
                        // Y=7, zombi camina hacia diagonal arriba derecha
    PosicionInterpolacion* posicionSpriteZombi;// posicion para la interpolacion
    
};

#endif	/* ZOMBI_H */