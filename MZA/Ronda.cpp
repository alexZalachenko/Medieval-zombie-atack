/* 
 * File:   Ronda.cpp
 * Author: Marta
 * 
 * Created on 8 de mayo de 2015, 12:07
 */

#define WIDTH 1280
#define HEIGHT 720

#include "Ronda.h"
#include "Zombi.h"

Ronda* Ronda::pinstance = 0;
Ronda* Ronda::Instance(){
    
    if(pinstance == 0){
        
        pinstance = new Ronda;
    }
    
    return pinstance;
}

Ronda::Ronda(){

    numOleada = 0;
    tam = 10;
}

void Ronda::cargarOleada() {

    vaciar();// vaciamos el vector para la siguiente oleada
    
    int especial = rand()%10+1;// zombie especial

    // bucle para crear los zombies de la oleada
    for(int i=0; i<tam; i++){
        
        // posicion inicial del zombie aleatoria
        float x = rand()%100-60;
        float y = rand()% 200-60;
        
        // recalculamos x e y para que no aparezcan dentro de la pantalla
        // los zombies apareceran fuera de ella y se moveran hasta verlos dentro
        while(x > 0 && x < 1280){
        
            x = rand()%3000;
        }
        
        while(y > 0 && y < 720){
        
            y = rand()%1000-100;
        }
        
        // zombie especial
        if(especial == i){
        
            colecZombi.push_back(new Zombi());// lo anyadimos a la coleccion
            colecZombi.back()->crearZombi(numOleada, true, x, y);
			
            // zombies normales
        }else{
        
            colecZombi.push_back(new Zombi());// lo anyadimos a la coleccion
            colecZombi.back()->crearZombi(numOleada, false, x, y);
        }
    } 
    
    //mostrarDatos();// mostramos los datos de los zombis de la oleada
    numOleada = numOleada + 1;// incrementamos el numero de la oleada
    
    // incrementamos hasta 40, tamanyo maximo de la oleada
    if(tam < 40){
    
        tam += 5;// incrementamos el tamanyo de la siguiente oleada
    }
}

void Ronda::mostrarDatos() {

    std::cout<<"******* OLEADA "<<numOleada<<"*******\n";
    
    for(int i=0; i<colecZombi.size(); i++){
    
        std::cout<<"Zombi"<<i<<"\n";
        std::cout<<"Vida:"<<colecZombi.at(i)->getVida()<<"\n";
        std::cout<<"Velocidad:"<<colecZombi.at(i)->getVelocidad()<<"\n";
        std::cout<<"\n";
    }
}

void Ronda::vaciar() {

    colecZombi.clear();
}

void Ronda::dibujar(sf::RenderWindow& ventana, float percenTick) {

    for(int i=0; i<colecZombi.size(); i++){
        
        colecZombi[i]->dibujar(ventana, percenTick);
    }
}

void Ronda::iniciarIA() {

    for(int i=0; i<colecZombi.size(); i++){
        
        colecZombi[i]->calculaIA();
    }
}

std::vector<Zombi*> Ronda::getColecZombi() {

    return colecZombi;
}

void Ronda::matarZombi(int i) {

    colecZombi.erase(colecZombi.begin()+i);
}
