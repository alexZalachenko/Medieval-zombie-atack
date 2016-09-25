/* 
 * File:   Jugador.cpp
 * Author: Marta
 * 
 * Created on 27 de abril de 2015, 18:04
 */

#include "Jugador.h"

#include "Jugador.h"

Jugador::Jugador() {
    jugadorOro=20000;
    jugadorPuntuacion=0;
    posicionSpriteEstructura=new PosicionInterpolacion();
    font.loadFromFile("resources/arial_narrow_7.ttf");
}

void Jugador::darOro(int n) {
    jugadorOro+=n;
}

void Jugador::quitarOro(int n) {
    jugadorOro-=n;
}

int Jugador::getOro() {
    return jugadorOro;
}

void Jugador::sumarPuntuacion(int n) {
    jugadorPuntuacion+=n;
}

int Jugador::mostrarPuntuacion(sf::RenderWindow& window) {
    jugadorPuntoSS.str("");
    jugadorPuntoSS<< jugadorPuntuacion;
    jugadorPuntoString= jugadorPuntoSS.str()+" Puntos";
    jugadorPuntoText.setString(jugadorPuntoString);
    jugadorPuntoText.setFont(font);
    jugadorPuntoText.setStyle(sf::Text::Bold);
//    jugadorPuntoText.setColor(sf::Color::White);
    jugadorPuntoText.setPosition(650,5);
    window.draw(jugadorPuntoText);
	return 0;
}


void Jugador::mostrarOro(sf::RenderWindow& window) {
    jugadorOroSS.str("");
    jugadorOroSS << jugadorOro;
    jugadorOroString = jugadorOroSS.str()+ " Oros";
    jugadorOroText.setString(jugadorOroString);
    jugadorOroText.setFont(font);
    jugadorOroText.setStyle(sf::Text::Bold);
//    jugadorOroText.setColor(sf::Color::White);
    jugadorOroText.setPosition(10,5);
    window.draw(jugadorOroText);
}

Jugador::Jugador(const Jugador& orig) {
}

Jugador::~Jugador() {
}


