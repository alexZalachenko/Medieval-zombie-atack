/* 
 * File:   Mapa.h
 * Author: Pablito
 *
 * Created on 24 de abril de 2015, 20:39
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <cctype>
#include "rapidxml.hpp"
#include "MenuLateralJuego.h"
#include "PosicionInterpolacion.h"
#ifndef MAPA_H
#define	MAPA_H

class Mapa {
protected:
    rapidxml::xml_document<> doc;

    rapidxml::xml_node<> *pRoot;
    rapidxml::xml_node<> *pNode;
    rapidxml::xml_attribute<> *pAttr;
    std::string source;
    sf::Texture celdasText;
    int tipoCelda;
    int posX1, posY1;
    bool prueba;
    sf::Sprite *texturaTrans;
    sf::IntRect texturaRectComodin1;
    sf::IntRect texturaRectComodin2;
    sf::IntRect texturaRectComodin3;
    sf::IntRect texturaRectComodin4;
    int elquedibujo;
    int xTrans, yTrans;
    //PosicionInterpolacion* posicionMapa;
    
    
public:
    static Mapa* Instance();
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    int numCelda;
    int pixelCelda;
    int*** celdasInt;
    sf::Sprite ****mapa;
    MenuLateralJuego* menuLat;
    int retornaValorCelda(int posX, int posY);
    int getDibujo();
    void setNuevaTextura(int posX, int posY, sf::IntRect posicionesTextura);
    float getPosicion(int posX, int posY, bool XoY);
    bool compruebaClick(int ratonPosicionX, int ratonPosicionY);
    void compruebaMovRaton(int ratonPosicionX, int ratonPosicionY);
    void draw(sf::RenderWindow &window, bool onClick, float tick);
    void setCelda(int posX, int posY, int nuevoValor);
    void noDibujo(int ratonPosicionX, int ratonPosicionY);
private:
    static Mapa* pinstance;


};

#endif	/* MAPA_H */

