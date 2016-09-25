/* 
 * File:   Ronda.h
 * Author: Marta
 *
 * Created on 8 de mayo de 2015, 12:07
 */

#ifndef RONDA_H
#define	RONDA_H

#include "Zombi.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

class Ronda {
public:
    
    Ronda();
    
    static Ronda* Instance();
    
    void cargarOleada();// metodo para crear la oleada
    void vaciar();// metodo para vaciar el array de los zombies
    void dibujar(sf::RenderWindow& ventana, float percenTick);
    void mostrarDatos();// para mostrar los datos de los zombis
    void iniciarIA();// para comenzar la IA de cada zombi
    
    // falta un metodo para delvolver el vector con los zombies, o modificar cargarOleada() para qeu devuelva el vector
    std::vector<Zombi*> getColecZombi();
    void matarZombi(int i);
    
private:

    Zombi zombi;
    static Ronda* pinstance;
    std::vector<Zombi*> colecZombi;// array con todos los zombies de la oleada
    int numOleada;// se inicia a uno
    int tam;// tamanyo del array de zombies
    
};

#endif	/* RONDA_H */

