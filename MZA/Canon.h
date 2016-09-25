/* 
 * File:   Canon.h
 * Author: Marta
 *
 * Created on 23 de abril de 2015, 21:03
 */

#include "Estructura.h"
#include "Estructura.h"
#include <string>
#include "PosicionInterpolacion.h"

#ifndef CANON_H
#define	CANON_H

class Canon : public Estructura{

private:
    int canonAtaque;
    int canonCadencia;
    
    sf::CircleShape canonArea;
    sf::CircleShape canonBola;
    
    sf::Texture canonBolaTextura;
    sf::Sprite canonBolaSprite;  
    
    PosicionInterpolacion* posicionBolaSprite;
    PosicionInterpolacion* posicionBola;
    
    float canonVelBola;

    int posEnemX;
    int posEnemY;
    
    int contVeces;
    
    double vectUniX, vectUniY;
    
    bool bola_creada;
    
public:
    Canon();
    Canon(const Canon& orig);
    virtual ~Canon();
    
    void aumentarNivelCanon(int n);
    void quitarVidaCanon();
    void posicionarArea();
    void crearBola();
    void setPositionBola(float,float);
    void setPositionBolaSprite(float,float);
    
    void disparo();
    
    sf::CircleShape getCanonArea(){
        return canonArea;
    }
    
    void canonUpdate();
    
    void repararCanon();
    void setCanonAtaque(int a);
    int getCanonAtaque();
    void setCanonCadencia(int c);
    int getCanonCadencia();


    void draw(sf::RenderWindow &window, float tick);

};

#endif	/* CANON_H */

