/* 
 * File:   Arquero.h
 * Author: Marta
 *
 * Created on 23 de abril de 2015, 20:44
 */
#include <SFML/Graphics.hpp>
#include "Estructura.h"
#include "Zombi.h"
#include <string>
#include "PosicionInterpolacion.h"
#ifndef ARQUERO_H
#define	ARQUERO_H

class Arquero: public Estructura {
private:
    int arqueroAtaque;
    int arqueroCadencia;
    
    sf::CircleShape arqueroArea;
    sf::RectangleShape arqueroFlecha;
    
    sf::Texture arqueroFlechaTextura;
    sf::Sprite arqueroFlechaSprite;
    
    PosicionInterpolacion* posicionFlechaSprite;
    PosicionInterpolacion* posicionFlecha;
    
    float arqueroVelFlecha;
    
    float posEnemX;
    float posEnemY;
    
    float m;
    
    int contVeces;
    
    double vectUniX, vectUniY;
    
    bool flecha_creada;
    
public:
    Arquero();
    Arquero(const Arquero& orig);
    virtual ~Arquero();

    void aumentarNivelArquero(int);
    void quitarVidaArquero();
    void posicionarArea();
    void crearFlecha();
    void setPositionFlecha(float,float);
    void setPositionFlechaSprite(float,float);
    
    void disparo();
    
    sf::CircleShape getArqueroArea(){
        return arqueroArea;
    }

    void arqueroUpdate();
        
    void repararArquero();
    void setArqueroAtaque(int a);
    int getArqueroAtaque();
    void setArqueroCadencia(int c);
    int getArqueroCadencia();

    
    void draw(sf::RenderWindow &window, float tick);

};

#endif	/* ARQUERO_H */

