/* 
 * File:   Estructura.h
 * Author: Usuario
 *
 * Created on 12 de marzo de 2015, 10:43
 */
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Boton.h"
#include "PosicionInterpolacion.h"
#include "ContenedorMZA.h"

#ifndef ESTRUCTURA_H
#define	ESTRUCTURA_H

typedef std::vector<int>  IntVector;

class Estructura {
 
protected:
    int estructuraVida;
    int estructuraNivel;
    int estructuraPrecio;
    bool estructuraMejorable;
    bool estructuraReparable;
       int estructuraPrecioReparar;    
       int estructuraTiempoWololo;
    int estructuraPrecioMejorar; 
    bool mostrarBoton;
    IntVector estructuraCoordenadasSprite;
    sf::Font font;
    sf::String estructuraNivelString;
    sf::Text estructuraNivelText;
    sf::Texture estructuraTextura;
    sf::Sprite estructuraSprite;
    sf::Sprite estructuraVidaSprite;
    sf::Texture estructuraVidaTextura;
    bool estructuraMostrarElemento;
    PosicionInterpolacion* posicionSpriteEstructura;
private:
    Boton* estructuraBotonMejorar;
    Boton* estructuraBotonReparar;
public:
    Estructura();
    Estructura(const Estructura& orig);
    virtual ~Estructura();
    void updateEstructura(float transcurrido,bool onClick,sf::Vector2i raton, bool mostrarElementos);
    void setEstructuraMostrarElemento(bool n);
    void crearBotones();
    void disminuirBarra();
    bool getEstructuraMostrarElemento();
    void setVidaEstructura(int);
    int getPrecioMejorar(){
        return estructuraPrecioMejorar;
    }
    int getPrecioReparar(){
        return estructuraPrecioReparar;
    }
    int getVidaEstructura() const{
        return estructuraVida;
    }
    
    void setNivelEstructura(int);
    int getNivelEstructura() const{
        return estructuraNivel;
    }
    void scaleBotones(float n);
    void setPrecioEstructura(int);
    int getPrecioEstructura() const{
        return estructuraPrecio;
    }   
    int mejorarEstructura();
    void repararEstructura();
    void setMejorableEstructura(bool);
    bool getMejorableEstructura() const{
        return estructuraMejorable;
    }
    
    void setReparableEstructura(bool);
    bool getReparableEstructura() const{
        return estructuraReparable;
    }
    
    void setCoordenadasSprite(IntVector);
    IntVector getCoordenadasSprite() const{
        return estructuraCoordenadasSprite;
    }
    int getAnchoEstructura(){
        return estructuraCoordenadasSprite[2];
    }
    int getAltoEstructura(){
        return estructuraCoordenadasSprite[3];
    }
    void cambiarSpriteEstructura(std::string);
    void modificarSpriteEstuctura(int n);
    void setTexturaEstructura(sf::Texture);
    sf::Texture getTexturaEstructura() const{
        return estructuraTextura;
    }
    sf::Text getStringNivelEstructura(int n);
    void setSpriteEstructura(sf::Sprite);
    sf::Sprite getSpriteEstructura() const{
        return estructuraSprite;
    }
    Boton* getBotonMejorarEstructura();
    Boton* getBotonRepararEstructura();
    void setPos(float x, float y);
    sf::Sprite colocarVidaEstructura();
    void draw(sf::RenderWindow &window, float tick);   
    void colocarBotones();
    void drawElementosEstructura(sf::RenderWindow &window);
    sf::Vector2i getEstructuraPosicion();
};

#endif	/* ESTRUCTURA_H */

