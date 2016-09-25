/* 
 * File:   Boton.cpp
 * Author: Marta
 * 
 * Created on 17 de marzo de 2015, 10:18
 */

#include "Boton.h"

Boton::Boton(sf::Font font) {
    fuente=font;
    botonRectangulo.setSize(sf::Vector2f(80, 25));     
    botonRectangulo.setOutlineThickness(1.5);
    botonRectangulo.setOutlineColor(sf::Color::Red);
    botonTexto.setFont(fuente);
//    botonTexto.setColor(sf::Color::Black);
    botonTexto.scale(0.5,0.5);
    
}


sf::RectangleShape Boton::getRectanguloBoton() {
    return botonRectangulo;
}

sf::Text Boton::getTextoBoton() {
    return botonTexto;
}
void Boton::ponerString(int n) {
    if(n==1)
            botonString="Nivel máx ";
    else
            botonString="Reparar ";
    
    botonTexto.setString(botonString);
    
}

void Boton::ponerStringYValor(int n, int valor){
    botonPrecio.str("");
    botonPrecio<<valor;
    if(n==1)
            botonString="Mejorar "+botonPrecio.str();
    else
            botonString="Reparar "+botonPrecio.str();
    
    botonTexto.setString(botonString);
    
}
void Boton::cambiarBoton(int n){
    /*if(n==1)
        botonTexto.setColor(sf::Color::Red);
    else if(n==2)
        botonTexto.setColor(sf::Color::Black);
    else
        botonTexto.setColor(sf::Color::Yellow);*/
        
}
void Boton::setPosicionBoton(int x, int y, int tam){
    botonRectangulo.setPosition(x+tam+5, y+5);
    botonTexto.setPosition(x+tam+10,y+5.1);
}
Boton::Boton(const Boton& orig) {
}

Boton::~Boton() {
}
void Boton::draw(sf::RenderWindow& window){
    window.draw(botonRectangulo);
    window.draw(botonTexto);
    
}

