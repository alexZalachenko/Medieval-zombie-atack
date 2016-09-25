/* 
 * File:   IAZombi.cpp
 * Author: Alex
 * 
 * Created on 27 de abril de 2015, 19:05
 */

#include "IAZombi.h"
#include "Celda.h"
#include "Fabrica.h"
#include <vector>
#include <stdlib.h> 
#include <iostream>
using namespace std;

IAZombi::IAZombi() {
}

IAZombi::IAZombi(const IAZombi& orig) {
}

IAZombi::~IAZombi() {
}

sf::Vector2i IAZombi::devuelveNextMov(sf::Vector2i posZ){
    return(sf::Vector2i(12,12));
    int ignoraEstructura=1;//ENTRE 1 E INFINITO(SI ES MAYOR QUE LA VIDA DE LA ESTRUCTURA PASA DE ELLA POR COMPLETO)
    
    vector<Celda*> abierta;
    vector<Celda*> cerrada;
    int ax, ay;
    int cd=14;//COSTE DE MOVERSE EN DIAGONAL
    int cr=10;//COSTE DE MOVERSE EN RECTO
    int cc=Fabrica::Instance()->getCastillo()->getEstructuraPosicion().x;//CELDA DEL CENTRO DEL CASTILLO
    int adyacentes=0;
    vector<Celda*>::iterator iterator;
    bool salto=false;
    
        //0 AÑADIMOS CELDA ORIGEN A LISTA ABIERTA
        Celda* celdaNula=NULL;
        abierta.push_back(new Celda(sf::Vector2i(posZ.x,posZ.y),0,0,0,celdaNula));
        
        while(true){
                iterator = abierta.begin();
                //1 COGEMOS PRIMER ELEMENTO DE LA LISTA ABIERTA Y LO SACAMOS Y LO METEMOS EN LISTA CERRADA
                cerrada.push_back(abierta.at(0));
                abierta.erase(iterator);
          
                //2 COGEMOS LAS CELDAS ADYACENTES A LA CELDA EXTRAIDA
                ax=cerrada.back()->getPos().x;
                ay=cerrada.back()->getPos().y;
                adyacentes=0;
                //celda dcha
                if(ax+1<24 && ay>0 && ay<24){
                    abierta.push_back(new Celda(sf::Vector2i(ax+1,ay),cerrada.back()->getG()+cr,(abs(cc-(ax+1))+abs(cc-ay))*cr,cerrada.back()->getG()+cr+(abs(cc-(ax+1))+abs(cc-ay))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda bajo
                if(ay+1<24 && ax>0 && ax<24){
                    abierta.push_back(new Celda(sf::Vector2i(ax,ay+1),cerrada.back()->getG()+cr,(abs(cc-ax)+abs(cc-(ay+1)))*cr,cerrada.back()->getG()+cr+(abs(cc-ax)+abs(cc-(ay+1)))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda izda
                if(ax-1>0 && ay>0 && ay<24){
                    abierta.push_back(new Celda(sf::Vector2i(ax-1,ay),cerrada.back()->getG()+cr,(abs(cc-(ax-1))+abs(cc-ay))*cr,cerrada.back()->getG()+cr+(abs(cc-(ax-1))+abs(cc-ay))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda arriba
                if(ay-1>0 && ax>0 && ax<24){
                    abierta.push_back(new Celda(sf::Vector2i(ax,ay-1),cerrada.back()->getG()+cr,(abs(cc-ax)+abs(cc-(ay-1)))*cr,cerrada.back()->getG()+cr+(abs(cc-ax)+abs(cc-(ay-1)))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda bajo-dcha
                if(ax+1<24 && ay+1<24){
                    abierta.push_back(new Celda(sf::Vector2i(ax+1,ay+1),cerrada.back()->getG()+cd,(abs(cc-(ax+1))+abs(cc-(ay+1)))*cr,cerrada.back()->getG()+cd+(abs(cc-(ax+1))+abs(cc-(ay+1)))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda bajo-izda
                if(ay+1<24 && ax-1>0){
                    abierta.push_back(new Celda(sf::Vector2i(ax-1,ay+1),cerrada.back()->getG()+cd,(abs(cc-(ax-1))+abs(cc-(ay+1)))*cr,cerrada.back()->getG()+cd+(abs(cc-(ax-1))+abs(cc-(ay+1)))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda arriba-izda
                if(ax-1>0 && ay-1>0){
                    abierta.push_back(new Celda(sf::Vector2i(ax-1,ay-1),cerrada.back()->getG()+cd,(abs(cc-(ax-1))+abs(cc-(ay-1)))*cr,cerrada.back()->getG()+cd+(abs(cc-(ax-1))+abs(cc-(ay-1)))*cr,cerrada.back()));
                    adyacentes++;
                }
                //celda arriba-dcha
                if(ay-1>0 && ax+1<24){
                    abierta.push_back(new Celda(sf::Vector2i(ax+1,ay-1),cerrada.back()->getG()+cd,(abs(cc-(ax+1))+abs(cc-(ay-1)))*cr,cerrada.back()->getG()+cd+(abs(cc-(ax+1))+abs(cc-(ay-1)))*cr,cerrada.back()));
                    adyacentes++;
                }
                
                //PILLAR MATRIZ DE ESTRUCTURAS.PARA CADA CELDA QUE COINCIDA CON LA POSICION DE UNA ESTRUCTURA LE SUMO A SU G LA VIDA DE LA ESTRUCTURA EN ESA POSICION
                int estructuras[25][25];
                for(int n=0;n<25;n++){
                    for(int w=0;w<25;w++){
                        estructuras[n][w]=-1;
                    }
                }
                for(int n=0;n<Fabrica::Instance()->getVector().size();n++){
                    if(Arquero* v = dynamic_cast<Arquero*>(Fabrica::Instance()->getVector().at(n))) {
                        estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y]=estructuras[v->getEstructuraPosicion().x+1][v->getEstructuraPosicion().y]=estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y+1]=estructuras[v->getEstructuraPosicion().x+1][v->getEstructuraPosicion().y+1]=Fabrica::Instance()->getVector().at(n)->getVidaEstructura()/ignoraEstructura;
                    }
                    else if(Canon* v = dynamic_cast<Canon*>(Fabrica::Instance()->getVector().at(n))) {
                        estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y]=estructuras[v->getEstructuraPosicion().x+1][v->getEstructuraPosicion().y]=estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y+1]=estructuras[v->getEstructuraPosicion().x+1][v->getEstructuraPosicion().y+1]=Fabrica::Instance()->getVector().at(n)->getVidaEstructura()/ignoraEstructura;
                    }
                    else if(Mina* v = dynamic_cast<Mina*>(Fabrica::Instance()->getVector().at(n))) {
                        estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y]=estructuras[v->getEstructuraPosicion().x+1][v->getEstructuraPosicion().y]=estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y+1]=estructuras[v->getEstructuraPosicion().x+1][v->getEstructuraPosicion().y+1]=Fabrica::Instance()->getVector().at(n)->getVidaEstructura()/ignoraEstructura;
                    }
                    else if(Muro* v = dynamic_cast<Muro*>(Fabrica::Instance()->getVector().at(n))) {
                       estructuras[v->getEstructuraPosicion().x][v->getEstructuraPosicion().y]=Fabrica::Instance()->getVector().at(n)->getVidaEstructura()/ignoraEstructura;
                    }
                    else if(Castillo* v = dynamic_cast<Castillo*>(Fabrica::Instance()->getVector().at(n))) {
                       
                    }
                }
            
                //PILLAR MATRIZ DE ESTRUCTURAS.PARA CADA CELDA QUE COINCIDA CON LA POSICION DE UNA ESTRUCTURA LE SUMO A SU G LA VIDA DE LA ESTRUCTURA EN ESA POSICION
                for(int i=abierta.size()-adyacentes;i<abierta.size();i++){
                    for(int n=0;n<Fabrica::Instance()->getVector().size();n++){
                        if(Fabrica::Instance()->getVector().at(n)->getEstructuraPosicion().x==abierta.at(i)->getPos().x && Fabrica::Instance()->getVector().at(n)->getEstructuraPosicion().y==abierta.at(i)->getPos().y){
                            abierta.at(i)->setG(abierta.at(i)->getG()+Fabrica::Instance()->getVector().at(n)->getVidaEstructura());
                            abierta.at(i)->setF(abierta.at(i)->getG()+abierta.at(i)->getH());
                        }
                    }
                }
                
                //3 PARA CADA CELDA ADYACENTE
                for(int i=abierta.size()-adyacentes;i<abierta.size();i++){
                        //SI LA CELDA ES CELDA DESTINO HEMOS ACABADO
                        if(abierta.at(i)->getPos().x==cc && abierta.at(i)->getPos().y==cc){
                             sf::Vector2i ret;
                             if(cerrada.size()==1)
                                 ret=sf::Vector2i(cc,cc);
                             else
                                 ret=sf::Vector2i(cerrada.at(1)->getPos().x,cerrada.at(1)->getPos().y);
                             for(int i=0;i<cerrada.size();i++){
                                free(cerrada.at(i));
                             }
                             for(int i=0;i<abierta.size();i++){
                                free(abierta.at(i));
                             }
                             return ret;
                        }
                        //SI LA CELDA ES UN TERRENO INFRANQUEABLE LA IGNORAMOS
                        //BLA BLA BLA
                        //SI LA CELDA YA ESTA EN LA LISTA CERRADA LA IGNORAMOS
                        for(int w=0;w<cerrada.size();w++){
                            if(cerrada.at(w)->getPos().x==abierta.at(i)->getPos().x && cerrada.at(w)->getPos().y==abierta.at(i)->getPos().y){
                                iterator = abierta.begin()+i;
                                free(abierta.at(i));
                                abierta.erase(iterator);
                                i--;
                                salto=true;
                                break;
                            }
                        }
                        if(salto){
                            salto=false;
                            continue;
                        }
                        //SI YA ESTA EN ABIERTA, COMPROBAMOS SI NUEVA G ES MEJOR QUE ACTUAL, Y SI LO ES RECALCULAMOS FACTORES Y PADRE ES CELDA EXTRAIDA.
                        //SI NO ES MEJOR, IGNORAMOS
                        for(int w=0;w<abierta.size();w++){
                            if(abierta.at(w)->getPos().x==abierta.at(i)->getPos().x && abierta.at(w)->getPos().y==abierta.at(i)->getPos().y){
                                if(w!=i){
                                    if(abierta.at(w)->getG()<abierta.at(i)->getG()){
                                        iterator = abierta.begin()+i;
                                        free(abierta.at(i));
                                        abierta.erase(iterator);
                                    }
                                    else{
                                        iterator = abierta.begin()+w;
                                        free(abierta.at(w));
                                        abierta.erase(iterator);
                                    }
                                    i--;
                                    break;
                                }
                            }
                        }
                }
                //4 ORDENAMOS LA LISTA ABIERTA EN FUNCION DEL FACTOR F
                for(int i=0;i<abierta.size();i++){ 
                    for(int j=i+1;j<abierta.size();j++){ 
                        if(abierta.at(j)->getF()<abierta.at(i)->getF())
                            std::swap(abierta.at(i), abierta.at(j));
                    } 
                } 
   
                
                /*cout<<"Tamaño cerrada: "<<cerrada.size()<<endl;
                for(int a=0;a<cerrada.size();a++){
                    cout<<"x:"<<cerrada.at(a)->getPos().x<<" y:"<<cerrada.at(a)->getPos().y<<" f:"<<cerrada.at(a)->getF()<<" g:"<<cerrada.at(a)->getG()<<" h:"<<cerrada.at(a)->getH()<<" padre:"<<cerrada.at(a)->getPadre()<<endl;
                }
                cout<<"Tamaño abierta: "<<abierta.size()<<endl;
                for(int a=0;a<abierta.size();a++){
                    cout<<"x:"<<abierta.at(a)->getPos().x<<" y:"<<abierta.at(a)->getPos().y<<" f:"<<abierta.at(a)->getF()<<" g:"<<abierta.at(a)->getG()<<" h:"<<abierta.at(a)->getH()<<" padre:"<<abierta.at(a)->getPadre()<<endl;
                }
                cout<<"************************************************************"<<endl;*/
    }
}
