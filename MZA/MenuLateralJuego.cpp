/* 
 * File:   MenuLateralJuego.cpp
 * Author: Alex
 * 
 * Created on 22 de marzo de 2015, 15:51
 */

#include "MenuLateralJuego.h"
#include "PoderWololo.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Estructura.h"
#include "Arquero.h"
#include "Fabrica.h"
using namespace std;

MenuLateralJuego::MenuLateralJuego(sf::Vector2u tam) {
    
    font.loadFromFile("resources/arial_narrow_7.ttf");
    wolo= new PoderWololo();
    reloj=sf::Clock();
    //CARGA DE LA TEXTURA
    if (!texture.loadFromFile("resources/spriteMenu.png")){
        std::cout << "Error cargando la imagen";
        exit(0);
    }
    //SPRITE PARA EL CONTENEDOR DEL MENU//
    spriteFondo.setTexture(texture);
    spriteFondo.setTextureRect(sf::IntRect(2,2,1000,400));
    spriteFondo.scale(tam.y/1000.0,1);
    spriteFondo.rotate(-90);
    spriteFondo.move(800,tam.y);
    //SPRITE PARA LA TORRETA DE ARQUEROS//
    spriteArq.setTexture(texture);
    spriteArq.setTextureRect(sf::IntRect(2,404,128,288));
    spriteArq.rotate(-90);
    spriteArq.move(840,tam.y*0.3);
    textoArq.setString("150 Oros");
    textoArq.setFont(font);
    textoArq.scale(0.7,0.7);
    textoArq.setPosition(1040,spriteArq.getPosition().y-50);
    //SPRITE PARA LA TORRETA DE ARQUEROSHOVER//
    spriteArqHover.setTexture(texture);
    spriteArqHover.setTextureRect(sf::IntRect(2,694,288,128));
    spriteArqHover.move(840,tam.y*0.14);//spriteArqHover.move(840,tam.y*0.175);
    //SPRITE PARA EL CAÑON//
    spriteCany.setTexture(texture);
    spriteCany.setTextureRect(sf::IntRect(132,404,128,275));
    spriteCany.rotate(-90);
    spriteCany.move(840,tam.y*0.48);//spriteCany.move(40,tam.y*0.44);
    textoCan.setString("180 Oros");
    textoCan.setFont(font);
    textoCan.scale(0.7,0.7);
    textoCan.setPosition(1040,spriteCany.getPosition().y-50);
    //SPRITE PARA EL CAÑONHOVER//
    spriteCanyHover.setTexture(texture);
    spriteCanyHover.setTextureRect(sf::IntRect(262,404,128,275));
    spriteCanyHover.rotate(-90);
    spriteCanyHover.move(840,tam.y*0.48);//spriteCanyHover.move(840,tam.y*0.44);
    //SPRITE PARA LA MINA//
    spriteMina.setTexture(texture);
    spriteMina.setTextureRect(sf::IntRect(292,681,257,128));
    spriteMina.move(840,tam.y*0.50);//spriteMina.move(40,tam.y*0.46);
    textoMina.setString("50 Oros");
    textoMina.setFont(font);
    textoMina.scale(0.7,0.7);
    textoMina.setPosition(1040,spriteMina.getPosition().y+80);
    
    //SPRITE PARA LA MINAHOVER//
    spriteMinaHover.setTexture(texture);
    spriteMinaHover.setTextureRect(sf::IntRect(392,456,257,128));
    spriteMinaHover.move(840,tam.y*0.50);//spriteMinaHover.move(840,tam.y*0.46);
    //SPRITE PARA EL MURO//
    spriteMuro.setTexture(texture);
    spriteMuro.setTextureRect(sf::IntRect(591,586,128,256));
    spriteMuro.rotate(-90);
    spriteMuro.move(840,tam.y*0.84);//spriteMuro.move(40,tam.y*0.73);
    textoMuro.setString("20 Oros");
    textoMuro.setFont(font);
    textoMuro.scale(0.7,0.7);
    textoMuro.setPosition(1040,spriteMuro.getPosition().y-50);
    
    //SPRITE PARA EL MUROHOVER//
    spriteMuroHover.setTexture(texture);
    spriteMuroHover.setTextureRect(sf::IntRect(651,456,256,128));
    spriteMuroHover.move(840,tam.y*0.68);//spriteMuroHover.move(840,tam.y*0.605);
    //SPRITE PARA EL WOLOLO POWER//
    spriteWolo.setTexture(texture);
    spriteWolo.setTextureRect(sf::IntRect(721,714,128,128));
    spriteWolo.rotate(-90);
    spriteWolo.move(1040,tam.y*0.97);//spriteWolo.move(240,tam.y*0.885);
    //SPRITE PARA EL WOLOLO POWER DESCARGADO//
    spriteWoloDescargado.setTexture(texture);
    spriteWoloDescargado.setTextureRect(sf::IntRect(721,586,128,128));
    spriteWoloDescargado.rotate(-90);
    spriteWoloDescargado.move(1040,tam.y*0.97);//spriteWoloDescargado.move(240,tam.y*0.885);
    //SPRITE PARA EL MARCO DE LA BARRA DE CARGA DEL WOLOLO//
    spriteFondoCarga.setTexture(texture);
    spriteFondoCarga.setTextureRect(sf::IntRect(392,404,595,50));
    spriteFondoCarga.move(825,tam.y*0.86);//spriteFondoCarga.move(25,tam.y*0.795);
    spriteFondoCarga.scale(0.35,1);
    //SPRITE PARA LA BARRA DE CARGA DEL WOLOLO//
    spriteBarraCarga.setTexture(texture);
    spriteBarraCarga.setTextureRect(sf::IntRect(2,824,587,42));
    spriteBarraCarga.move(827,tam.y*0.865);//spriteBarraCarga.move(27,tam.y*0.80);
    
}

MenuLateralJuego::MenuLateralJuego(const MenuLateralJuego& orig) {
}

MenuLateralJuego::~MenuLateralJuego() {
}
sf::Sprite MenuLateralJuego::getSprites(int opcion){
    switch(opcion){
        case 1:
            return spriteArqHover;
            break;
        case 2:
            return spriteCanyHover;
            break;
        case 3:
            return spriteMinaHover;
            break;
        case 4:
            return spriteMuroHover;
            break;
    }
}

void MenuLateralJuego::Actualiza(sf::RenderWindow& window, bool onClick){
    window.draw(spriteFondo);
    window.draw(spriteArq);
    
    window.draw(spriteCany);
    window.draw(spriteMuro);
    window.draw(spriteMina);
    
    //PARA MOSTRAR O NO EL HOVER DE LAS ESTRUCTURAS
    int x=sf::Mouse::getPosition(window).x, y=sf::Mouse::getPosition(window).y;
    if(841<x && x<1128 && 0<y){
        if(111<y && y<238)
            window.draw(spriteArqHover);
        else if(256<y && y<383)
            window.draw(spriteCanyHover);
        else if(400<y && y<526)
            window.draw(spriteMinaHover);
        else if(544<y && y<671)
            window.draw(spriteMuroHover);
    }
    if(wolo->getEstado()==true){
        sf::CircleShape c=sf::CircleShape(10,30);
        c.setPosition(x-5,y-5);
        window.draw(c);
    }
    //COMPROBAR SI SE DEBE ACTIVAR WOLOLO
    if(onClick==true && wolo->getEstado()==false)
        if(1054<x && x<1149 && 660<y && y<759){
            wolo->cambiaEstado();
            cout<<"click en wololo"<<endl;
        }
    //SI EL PODER DEL WOLOLO ESTA ACTIVO
    if(onClick==true && wolo->getEstado()==true){
        Estructura *clicada=NULL;
        //OBTENGO LA ESTRUCTUCA CLICADA
        clicada=Fabrica::Instance()->getEstructuraHover(x,y);
        //AUMENTO SUS CARACTERISTICAS EN FUNCION DEL NIVEL DEL PODER DEL WOLOLO
        if(clicada!=NULL){
            cout<<"click en estructura"<<endl;
            wolo->usarWololo(clicada);
        }
        else
            cout<<"clik en campo"<<endl;
    }
    
    //AUMENTAR LA BARRA DE CARGA DEL WOLOLO
    if(wolo->getCarga()<5){
        if(wolo->getCarga()==-1.0){
            reloj.restart();
            wolo->setCarga(0.0);
        }
        if(reloj.getElapsedTime().asSeconds()>=3){
            wolo->setCarga(wolo->getCarga()+1);
            reloj.restart();
        }
        window.draw(spriteWoloDescargado);
        spriteBarraCarga.setScale(0.35*(wolo->getCarga()/5.0),1);
    }
    else
        window.draw(spriteWolo);
    window.draw(spriteFondoCarga);
    window.draw(spriteBarraCarga);
    window.draw(textoArq);
    window.draw(textoCan);
    window.draw(textoMina);
    window.draw(textoMuro);
}


PoderWololo* MenuLateralJuego::getPoderWololo(){
    return wolo;
}