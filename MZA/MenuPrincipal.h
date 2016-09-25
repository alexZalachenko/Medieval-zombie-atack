/* 
 * File:   MenuPrincipal.h
 * Author: Pablito
 *
 * Created on 27 de abril de 2015, 11:32
 */
#include <SFML/Graphics.hpp>
#include "BotonMenu.h"
#ifndef MENUPRINCIPAL_H
#define	MENUPRINCIPAL_H

class MenuPrincipal {
public:
    
    static MenuPrincipal* Instance();
    BotonMenu* botonJugar;
    BotonMenu* botonOpciones;
    BotonMenu* botonLogros;
    sf::Sprite fondoMenuSprite;
    sf::Texture fondoMenuText;
    BotonMenu* getBotonJugar();
    BotonMenu* getBotonOpciones();
    BotonMenu* getBotonLogros();
    bool updateMenuPpal(bool onClick, sf::Vector2i raton);
    void draw(sf::RenderWindow &window, float percenTick);
    MenuPrincipal();
    MenuPrincipal(const MenuPrincipal& orig);
    virtual ~MenuPrincipal();
private:
    static MenuPrincipal* pinstance;

};

#endif	/* MENUPRINCIPAL_H */

