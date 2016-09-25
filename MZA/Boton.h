/* 
 * File:   Boton.h
 * Author: Marta
 *
 * Created on 17 de marzo de 2015, 10:18
 */
#include <SFML/Graphics.hpp>
#include <string>
#ifndef BOTON_H
#define	BOTON_H
#include <string>
#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
class Boton {

    
private:
    sf::String botonString;
    sf::Text botonTexto;
    sf::RectangleShape botonRectangulo;
    sf::Font fuente;
    std::stringstream botonPrecio;
 public:
    Boton(sf::Font font);
    //Boton2();
    Boton(const Boton& orig);
    virtual ~Boton();
    sf::RectangleShape getRectanguloBoton();
    sf::Text getTextoBoton();
    void cambiarBoton(int n);
    void ponerStringYValor(int n, int valor);
    void setPosicionBoton(int x, int y, int tam);
    void ponerString(int n);
    void draw(sf::RenderWindow &window); 
};

#endif	/* BOTON_H */

