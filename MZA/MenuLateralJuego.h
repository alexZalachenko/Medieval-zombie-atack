/* 
 * File:   MenuLateralJuego.h
 * Author: Alex
 *
 * Created on 22 de marzo de 2015, 15:51
 */

#ifndef MENULATERALJUEGO_H
#define	MENULATERALJUEGO_H
#include <SFML/Graphics.hpp>
#include "PoderWololo.h"

class MenuLateralJuego {
public:
    MenuLateralJuego(sf::Vector2u tam);
    MenuLateralJuego(const MenuLateralJuego& orig);
    virtual ~MenuLateralJuego();
    void Actualiza(sf::RenderWindow& window, bool onClick);
    sf::Sprite getSprites(int opcion);
    PoderWololo* getPoderWololo(); 
private:
    PoderWololo* wolo;
    sf::Clock reloj;
    sf::Texture texture;
    sf::Sprite spriteFondo;
    sf::Sprite spriteArq;
    sf::Sprite spriteArqHover;
    sf::Sprite spriteCany;
    sf::Sprite spriteCanyHover;
    sf::Sprite spriteMina;
    sf::Sprite spriteMinaHover;
    sf::Sprite spriteMuro;
    sf::Sprite spriteMuroHover;
    sf::Sprite spriteWolo;
    sf::Sprite spriteWoloDescargado;
    sf::Sprite spriteFondoCarga;
    sf::Sprite spriteBarraCarga;
    sf::Font font;
    sf::Text textoArq;
    sf::Text textoCan;
    sf::Text textoMuro;
    sf::Text textoMina;
};

#endif	/* MENULATERALJUEGO_H */

