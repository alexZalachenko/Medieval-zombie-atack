/* 
 * File:   MenuPrincipal.cpp
 * Author: Pablito
 * 
 * Created on 27 de abril de 2015, 11:32
 */

#include "MenuPrincipal.h"
using namespace std;

MenuPrincipal* MenuPrincipal::pinstance = 0;
MenuPrincipal* MenuPrincipal::Instance(){
    if(pinstance == 0)
        pinstance = new MenuPrincipal;
    return pinstance;
}
MenuPrincipal::MenuPrincipal() {
    botonJugar = new BotonMenu();
    botonOpciones = new BotonMenu();
    botonLogros = new BotonMenu();
    
    botonJugar->ponerString(1);
    botonOpciones->ponerString(2);
    botonLogros->ponerString(3);
    
    botonJugar->setPosicionBotonMenu(520,561);
    botonOpciones->setPosicionBotonMenuO(520,627);
    botonLogros->setPosicionBotonMenu(520,688);
    if(!fondoMenuText.loadFromFile("resources/fondo.png")){
        //std::cerr << "Error cargando la imagen";
        exit(0);
    }
    fondoMenuSprite.setTexture(fondoMenuText);
    fondoMenuSprite.setOrigin(0,0);
    fondoMenuSprite.setPosition(0,0);
}
bool MenuPrincipal::updateMenuPpal(bool onClick, sf::Vector2i raton){
    sf::RectangleShape rectangle(sf::Vector2f(3, 3));
     
    rectangle.setPosition(raton.x,raton.y);
    sf::FloatRect bond=rectangle.getGlobalBounds();
    if(bond.intersects(getBotonJugar()->getRectanguloBotonMenu().getGlobalBounds())){
        botonJugar->cambiarBotonMenu(1);
        botonLogros->cambiarBotonMenu(2);
        botonOpciones->cambiarBotonMenu(2);
        if(onClick){
            return true;
        }

    }
    else if(bond.intersects(getBotonOpciones()->getRectanguloBotonMenu().getGlobalBounds())){
        botonJugar->cambiarBotonMenu(2);
        botonLogros->cambiarBotonMenu(2);
        botonOpciones->cambiarBotonMenu(1);
    }
    else if(bond.intersects(getBotonLogros()->getRectanguloBotonMenu().getGlobalBounds())){
        botonJugar->cambiarBotonMenu(2);
        botonLogros->cambiarBotonMenu(1);
        botonOpciones->cambiarBotonMenu(2);
    }
    else{
        botonJugar->cambiarBotonMenu(2);
        botonLogros->cambiarBotonMenu(2);
        botonOpciones->cambiarBotonMenu(2);
    }
}
void MenuPrincipal::draw(sf::RenderWindow& window, float percenTick){
    window.draw(fondoMenuSprite);
    botonJugar->draw(window);
    botonOpciones->draw(window);
    botonLogros->draw(window);
}
BotonMenu* MenuPrincipal::getBotonJugar(){
    return botonJugar;
}
BotonMenu* MenuPrincipal::getBotonOpciones(){
    return botonOpciones;
}
BotonMenu* MenuPrincipal::getBotonLogros(){
    return botonLogros;
}

MenuPrincipal::MenuPrincipal(const MenuPrincipal& orig) {
}

MenuPrincipal::~MenuPrincipal() {
}

