/* 
 * File:   BotonMenu.cpp
 * Author: Pablito
 * 
 * Created on 27 de abril de 2015, 12:05
 */

#include "BotonMenu.h"

BotonMenu::BotonMenu() {
    botonRectangulo.setSize(sf::Vector2f(150, 50));    
    font.loadFromFile("resources/arial_narrow_7.ttf");
    botonRectangulo.setFillColor(sf::Color::Black);
    botonRectangulo.setOutlineThickness(2.5);
    botonRectangulo.setOutlineColor(sf::Color::Red);
    botonTexto.setFont(font);
//    botonTexto.setColor(sf::Color::White);
    
}


sf::RectangleShape BotonMenu::getRectanguloBotonMenu() {
    return botonRectangulo;
}

sf::Text BotonMenu::getTextoBotonMenu() {
    return botonTexto;
}

void BotonMenu::ponerString(int n){
    if(n==1)
            botonString="Jugar";
    else if(n==2)
            botonString="Opciones";
    else if(n==3)
        botonString="Logros";
    
    botonTexto.setString(botonString);
    
}
void BotonMenu::cambiarBotonMenu(int n){
    /*if(n==1)
        botonTexto.setColor(sf::Color::Red);
    else if(n==2)
        botonTexto.setColor(sf::Color::White);
    else
        botonTexto.setColor(sf::Color::Yellow);*/
        
}
void BotonMenu::setPosicionBotonMenu(int x, int y){
    botonRectangulo.setPosition(x, y);
    botonTexto.setPosition(x+40,y+8);
}
void BotonMenu::setPosicionBotonMenuO(int x, int y){
    botonRectangulo.setPosition(x, y);
    botonTexto.setPosition(x+20,y+8);
}
BotonMenu::BotonMenu(const BotonMenu& orig) {
}

BotonMenu::~BotonMenu() {
}
void BotonMenu::draw(sf::RenderWindow& window){
    window.draw(botonRectangulo);
    window.draw(botonTexto);
}
