/* 
 * File:   BotonMenu.h
 * Author: Pablito
 *
 * Created on 27 de abril de 2015, 12:05
 */
#include <SFML/Graphics.hpp>
#include <string>
#ifndef BOTONMENU_H
#define	BOTONMENU_H

class BotonMenu {

    
private:
    sf::String botonString;
    sf::Text botonTexto;
    sf::RectangleShape botonRectangulo;
    sf::Font font;
    
 public:
    BotonMenu();
    //BotonMenu2();
    BotonMenu(const BotonMenu& orig);
    virtual ~BotonMenu();
    sf::RectangleShape getRectanguloBotonMenu();
    sf::Text getTextoBotonMenu();
    void cambiarBotonMenu(int n);
    
    void setPosicionBotonMenu(int x, int y);
    void setPosicionBotonMenuO(int x, int y);
    void ponerString(int n);
    void draw(sf::RenderWindow &window); 
};

#endif	/* BOTONMENU_H */

