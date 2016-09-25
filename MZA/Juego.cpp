/* 
 * File:   Juego.cpp
 * Author: Marta
 * 
 * Created on 5 de mayo de 2015, 9:31
 */
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Estructura.h"
#include "Castillo.h"
#include "Boton.h"
#include "Fabrica.h"
#include "Zombi.h"
#include "Ronda.h"
#include <sstream>
#include <fstream>
#include <cctype>
#include "rapidxml.hpp"
#include "mapa.h"
#include "MenuLateralJuego.h"
#include "MenuPrincipal.h"
#include "Juego.h"
Juego* Juego::pinstance = 0;
Juego* Juego::Instance() {
    
    if(pinstance==0)
        pinstance=new Juego;
    return pinstance;
}


Juego::Juego() {
    mapa = Mapa::Instance();
    menuPrinc = MenuPrincipal::Instance();
    ronda= Ronda::Instance();
    fabrica = Fabrica::Instance();
    enPausa=false;
    nuevaOleada = false;
}

void Juego::terminarJuego() {
    //delete fabrica;
    //delete ronda;
    cout<<"GAME OVER"<<endl;
}

void Juego::setEnPausa() {
    if(enPausa)
        enPausa=false;
    else
        enPausa=true;
}

void Juego::setEstado(bool state) {
    estado=state;
}

bool Juego::getEstado() {
    return estado;
}

Mapa* Juego::getMapa() {
    return mapa;
}


MenuPrincipal* Juego::getMenu() {
    return menuPrinc;
}

void Juego::actualizaJuego(float transcurrido, bool onClick, sf::Vector2i raton) {
    if(estado && fabrica->getVector().size()==0){
        terminarJuego();
    }
    if(!enPausa){
        fabrica->update(transcurrido,onClick,raton);
        if(Ronda::Instance()->getColecZombi().empty()==true){
            
                    Ronda::Instance()->cargarOleada();
                }
    }
    if(!estado){
            estado = menuPrinc->updateMenuPpal(onClick, raton);
    }
}

void Juego::comprobarRaton(int x, int y) {
    
    mapa->compruebaMovRaton(x,y);
}

Fabrica* Juego::getFabrica() {
    return fabrica;
}

void Juego::renderJuego(sf::RenderWindow& window, float percenTick, bool onClick) {
    if(estado){
            Mapa::Instance()->draw(window, onClick, percenTick);
            Fabrica::Instance()->render(window,percenTick);
            if(!enPausa){

                // cargamos una  nueva oleada cuando el vector de zombis este vacio
                
                
                // sirve como prueba para comprobar que carga la siguiente oleada
                /*if(Fabrica::Instance()->getVector().size()==3 && nuevaOleada==false){
                
                    Ronda::Instance()->cargarOleada();
                    nuevaOleada = true;
                }*/
                
                // los zombies de la ronda se dibujan si hay construida alguna estructura a parte del castillo
                if(Fabrica::Instance()->getVector().size()>31){
                    
                    Ronda::Instance()->dibujar(window, percenTick);
                    Ronda::Instance()->iniciarIA();
                }
            }
    }else{
        MenuPrincipal::Instance()->draw(window, percenTick);
    }
}


Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}
