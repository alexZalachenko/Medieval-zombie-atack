/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 12 de marzo de 2015, 10:42
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
using namespace std;
#define UPDATE_TICK_TIME 1/15

int main(int argc, char** argv) {
    Juego::Instance();
    Juego::Instance()->setEstado(false);
    //Mapa::Instance();
    //MenuPrincipal::Instance();
    //bool estado=false;
    //Ronda::Instance();// fabrica de zombies
    // para cargar una nueva oleada
    
    //Renderizamos la pantalla, window es una variable (objeto) de tipo RenderWindow
    sf::RenderWindow window(sf::VideoMode((Mapa::Instance()->numCelda-1)*Mapa::Instance()->pixelCelda+400, (Mapa::Instance()->numCelda-1)*Mapa::Instance()->pixelCelda), "Mapa");
    //sf::RenderWindow window(sf::VideoMode(768,768),"Castillo");
    window.setFramerateLimit(60);
    sf::Clock updatec;
    sf::Time elapsed;
    sf::Vector2i raton;
    //Fabrica::Instance();
    
    bool onClick=false;
    
    //Bucle principal
    while( window.isOpen() ){
        if(updatec.getElapsedTime().asSeconds() > UPDATE_TICK_TIME){
        //Creamos la variable de tipo evento para almacenar las entradas del usuario
            sf::Event evento;
            onClick=false;
            elapsed = updatec.restart();
             while (window.pollEvent(evento)) {

                switch(evento.type){
                    //Evento que se activa si pulso en salir de la pantalla
                    
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::MouseMoved:
                        raton.x=evento.mouseMove.x;
                        raton.y=evento.mouseMove.y;

                        if(Juego::Instance()->getEstado()){
                            Juego::Instance()->comprobarRaton(raton.x,raton.y);
                            
                        }
                        break;
                    case sf::Event::MouseButtonPressed:
                        switch(evento.key.code){
                            case sf::Mouse::Left:
                                raton.x=evento.mouseButton.x;
                                raton.y=evento.mouseButton.y;
                                onClick=true;
                                if(Juego::Instance()->getEstado()){
                                    Juego::Instance()->getMapa()->compruebaClick(raton.x,raton.y);
                                }
                                break;
                            case sf::Mouse::Right:
                                raton.x=evento.mouseButton.x;
                                raton.y=evento.mouseButton.y;
                                onClick=true;
                                if(Juego::Instance()->getEstado()){
                                    Juego::Instance()->getMapa()->noDibujo(raton.x,raton.y);
                                }
                                break;
                        }
                        break;
                        case sf::Event::KeyPressed:
                        switch(evento.key.code){
                            case sf::Keyboard::Escape:
                                Juego::Instance()->setEnPausa();
                            break;
                        }
                
                }
                
             }
            
        }
        Juego::Instance()->actualizaJuego(elapsed.asMilliseconds(),onClick,raton);
        
        
        
      
        //Al final de cada iteracion, limpiamos la pantalla y diponemos la nueva
        window.clear();
        //hacemos la interpolacion
        float percentTick = std::min(1.f, (float)(updatec.getElapsedTime().asSeconds()/UPDATE_TICK_TIME));
            Juego::Instance()->renderJuego(window, percentTick,onClick);
        
        

        
        
        
        
        window.display();
    }
    return 0;
}

