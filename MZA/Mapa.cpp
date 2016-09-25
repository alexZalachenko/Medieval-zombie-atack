/* 
 * File:   Mapa.cpp
 * Author: Pablito
 * 
 * Created on 24 de abril de 2015, 20:39
 */

#include "Mapa.h"
#include "Fabrica.h"
using namespace std;
Mapa* Mapa::pinstance = 0;
Mapa* Mapa::Instance(){
    if(pinstance == 0)
        pinstance = new Mapa;
    return pinstance;
}

Mapa::Mapa() {
    std::ifstream file("mapa.tmx");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    pRoot = doc.first_node();
    pNode = pRoot->first_node("tileset");
    pAttr = pRoot->first_attribute("width");
    numCelda = atoi(pAttr->value());
    pAttr = pRoot->first_attribute("tilewidth");
    pixelCelda = atoi(pAttr->value());
    pAttr = pNode->first_node("image")->first_attribute("source");
    source = pAttr->value();
    if (!celdasText.loadFromFile(source))
    {
        std::cerr << "Error cargando la imagen celdas.png";
        exit(0);
    }
    pNode = pNode->next_sibling();
    pNode = pNode->first_node("data");
    pNode = pNode->first_node("tile");
    celdasInt = new int**[numCelda];
    tipoCelda=0;
    mapa = new sf::Sprite***[numCelda];
    int x=0,y=0;
    for(int i=0;i<numCelda;i++){
        mapa[i]=new sf::Sprite**[numCelda];
        celdasInt[i] = new int*[numCelda];
        for(int j=0;j<numCelda;j++){
            celdasInt[i][j]= new int[2];
            celdasInt[i][j][0]= atoi(pNode->first_attribute("gid")->value());
            celdasInt[i][j][1]=6;
            tipoCelda=atoi(pNode->first_attribute("gid")->value());
            mapa[i][j] = new sf::Sprite*[2];
            if(tipoCelda==1){
                mapa[i][j][0]= new sf::Sprite(celdasText);
                mapa[i][j][0]->setOrigin(0,0);
                mapa[i][j][0]->setTextureRect(sf::IntRect(0,0,pixelCelda,pixelCelda));
                mapa[i][j][0]->setPosition(x,y);
            }
            else if(tipoCelda==2){
                mapa[i][j][0]= new sf::Sprite(celdasText);
                mapa[i][j][0]->setOrigin(0,0);
                mapa[i][j][0]->setTextureRect(sf::IntRect(pixelCelda,0,pixelCelda,pixelCelda));
                mapa[i][j][0]->setPosition(x,y);
            }
            else if(tipoCelda==3){
                mapa[i][j][0]= new sf::Sprite(celdasText);
                mapa[i][j][0]->setOrigin(0,0);
                mapa[i][j][0]->setTextureRect(sf::IntRect(pixelCelda*2,0,pixelCelda,pixelCelda));
                mapa[i][j][0]->setPosition(x,y);
            }
            mapa[i][j][1]=new sf::Sprite(celdasText);
            mapa[i][j][1]->setOrigin(0,0);
            mapa[i][j][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
            mapa[i][j][1]->setPosition(x,y);
            x=x+32;
            pNode=pNode->next_sibling(); 
        }   
        x=0;
        y=y+32;
    }
    //posicionMapa->setPos(0,0);
    posX1=-1;
    posY1=-1;
    prueba=false;
    
    elquedibujo=0;
    sf::Vector2u tamanyo;
    tamanyo.x = 1200;
    tamanyo.y=800;
    menuLat = new MenuLateralJuego(tamanyo);
    texturaTrans = new sf::Sprite(celdasText);
    texturaTrans->setOrigin(0,0);
    texturaTrans->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
    
    
    
    
}

int Mapa::retornaValorCelda(int posX, int posY){
    return celdasInt[posX][posY][0];
}

void Mapa::setNuevaTextura(int posX, int posY, sf::IntRect posicionesTextura){
    mapa[posX][posY][0]->setTextureRect(posicionesTextura);
    
}

float Mapa::getPosicion(int posX, int posY, bool XoY){
    if(XoY){
        return mapa[posX][posY][0]->getPosition().x;
    }else{
        return mapa[posX][posY][0]->getPosition().y;
    }
}
void Mapa::setCelda(int posX, int posY, int nuevoValor){
    celdasInt[posX][posY][0]=nuevoValor;
    
}
int Mapa::getDibujo(){
    return elquedibujo;
}
void Mapa::noDibujo(int ratonPosicionX, int ratonPosicionY){
    if(prueba){
        ratonPosicionX=ratonPosicionX/32;
        ratonPosicionY=ratonPosicionY/32;
        posX1=-1;
        posY1=-1;
        prueba=false;
        elquedibujo=0;
        mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
        mapa[ratonPosicionY+1][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
        mapa[ratonPosicionY][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
        mapa[ratonPosicionY+1][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
    }
}
bool Mapa::compruebaClick(int ratonPosicionX, int ratonPosicionY){
    sf::RectangleShape rectangle(sf::Vector2f(3, 3));
    rectangle.setPosition(ratonPosicionX, ratonPosicionY);
    sf::FloatRect bond=rectangle.getGlobalBounds();
    if(bond.intersects(menuLat->getSprites(1).getGlobalBounds())){ 
        
        if(Fabrica::Instance()->getJugador()->getOro()>=150){
            if(!prueba){
                prueba=true;
                elquedibujo=1;
                
            }
        }
        
    }
    else if(bond.intersects(menuLat->getSprites(2).getGlobalBounds())){ 
        if(Fabrica::Instance()->getJugador()->getOro()>=180){
            if(!prueba){
                prueba=true;
                elquedibujo=2;
            }
        }
        
    }
    else if(bond.intersects(menuLat->getSprites(3).getGlobalBounds())){ 
        if(Fabrica::Instance()->getJugador()->getOro()>=50){
            if(!prueba){
                prueba=true;
                elquedibujo=3;
            }
        }
    }
    else if(bond.intersects(menuLat->getSprites(4).getGlobalBounds())){ 
        if(Fabrica::Instance()->getJugador()->getOro()>=20){
            if(!prueba){
                prueba=true;
                elquedibujo=4;
            }
        }
    }
    else{
        if(prueba){
            ratonPosicionX=ratonPosicionX/32;
            ratonPosicionY=ratonPosicionY/32;
            if(retornaValorCelda(ratonPosicionX,ratonPosicionY)!=3 && getPosicion(ratonPosicionY, ratonPosicionX, true)<768 && getPosicion(ratonPosicionY, ratonPosicionX, false)<768){
                if(elquedibujo==4){
                    
                        celdasInt[ratonPosicionX][ratonPosicionY][0]=3;
                        setNuevaTextura(ratonPosicionY, ratonPosicionX, sf::IntRect(pixelCelda*2,0,pixelCelda,pixelCelda));
                        mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                        Fabrica::Instance()->construirEstructura(elquedibujo,ratonPosicionX*32,ratonPosicionY*32);

                    prueba=false;
                    posY1=-1;
                    posX1=-1;
                    
                    elquedibujo==0;
                }else{
                    if(retornaValorCelda(ratonPosicionX+1,ratonPosicionY)==1 && retornaValorCelda(ratonPosicionX+1,ratonPosicionY+1)==1 && retornaValorCelda(ratonPosicionX,ratonPosicionY+1)==1){
                        
                            celdasInt[ratonPosicionX][ratonPosicionY][0]=3;
                            celdasInt[ratonPosicionX+1][ratonPosicionY][0]=3;
                            celdasInt[ratonPosicionX][ratonPosicionY+1][0]=3;
                            celdasInt[ratonPosicionX+1][ratonPosicionY+1][0]=3;
                            setNuevaTextura(ratonPosicionY, ratonPosicionX, sf::IntRect(pixelCelda*2,0,pixelCelda,pixelCelda));
                            setNuevaTextura(ratonPosicionY+1, ratonPosicionX, sf::IntRect(pixelCelda*2,0,pixelCelda,pixelCelda));
                            setNuevaTextura(ratonPosicionY, ratonPosicionX+1, sf::IntRect(pixelCelda*2,0,pixelCelda,pixelCelda));
                            setNuevaTextura(ratonPosicionY+1, ratonPosicionX+1, sf::IntRect(pixelCelda*2,0,pixelCelda,pixelCelda));
                            mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                            mapa[ratonPosicionY+1][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                            mapa[ratonPosicionY][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                            mapa[ratonPosicionY+1][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                            Fabrica::Instance()->construirEstructura(elquedibujo,ratonPosicionX*32,ratonPosicionY*32);
                            
                        
                        prueba=false;
                            posY1=-1;
                            posX1=-1;
                            
                        
                        elquedibujo==0;
                    }
                }
                

             }
        }
    }
    return prueba;
}
void Mapa::compruebaMovRaton(int ratonPosicionX, int ratonPosicionY){
    
    if(prueba){
        ratonPosicionX=ratonPosicionX/32;
        ratonPosicionY=ratonPosicionY/32;
        
        if(ratonPosicionX<25){
            //texturaRectComodin1 = mapa[ratonPosicionY][ratonPosicionX]->getTextureRect();
            if(elquedibujo==4){
                if(ratonPosicionY!=posY1 || ratonPosicionX!=posX1){
                    if(posX1!=-1){
                            mapa[posY1][posX1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                    }
                    posX1=ratonPosicionX;
                    posY1=ratonPosicionY;


                }
                else{
                    if(posX1!=-1){ 
                        if(celdasInt[ratonPosicionX][ratonPosicionY][0]==1){

                            mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                        }
                        else if(celdasInt[ratonPosicionX][ratonPosicionY][0]!=1){

                            mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                        }
                    }
                    posX1=ratonPosicionX;
                    posY1=ratonPosicionY;


                }
            }else{
                if(ratonPosicionY!=posY1 || ratonPosicionX!=posX1){

                    if(posX1!=-1){
                        mapa[posY1][posX1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                        if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().x<768){
                            mapa[posY1][posX1+1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));
                        }
                        if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().y<768){
                            mapa[posY1+1][posX1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));

                        }
                        if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().y<768 && mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().x<768){

                                mapa[posY1+1][posX1+1][1]->setTextureRect(sf::IntRect(pixelCelda*2,pixelCelda,pixelCelda,pixelCelda));

                        }
                        
                        

                    }


                    posX1=ratonPosicionX;
                    posY1=ratonPosicionY;


                }
                else{

                    if(posX1!=-1){ 
                        if(celdasInt[ratonPosicionX][ratonPosicionY][0]==1){

                            mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                            if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().x<768){
                                if(celdasInt[ratonPosicionX+1][ratonPosicionY][0]==1){
                                    mapa[ratonPosicionY][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                                }else{
                                    mapa[ratonPosicionY][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                                }
                            }
                            if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().y<768){
                                if(celdasInt[ratonPosicionX][ratonPosicionY+1][0]==1){
                                    mapa[ratonPosicionY+1][ratonPosicionX][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                                }else{
                                    mapa[ratonPosicionY+1][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                                }

                            }
                            if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().y<768 && mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().x<768){
                                if(celdasInt[ratonPosicionX+1][ratonPosicionY+1][0]==1){
                                    mapa[ratonPosicionY+1][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                                }else{
                                    mapa[ratonPosicionY+1][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                                }
                            }
                        }
                        else{

                            mapa[ratonPosicionY][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                            if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().x<768){
                                if(celdasInt[ratonPosicionX+1][ratonPosicionY][0]==1){
                                    mapa[ratonPosicionY][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                                }else{
                                    mapa[ratonPosicionY][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                                }
                            }
                            if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().y<768){
                                if(celdasInt[ratonPosicionX][ratonPosicionY+1][0]==1){
                                    mapa[ratonPosicionY+1][ratonPosicionX][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                                }else{
                                    mapa[ratonPosicionY+1][ratonPosicionX][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                                }

                            }
                            if(mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().y<768 && mapa[ratonPosicionY][ratonPosicionX][0]->getPosition().x<768){
                                if(celdasInt[ratonPosicionX+1][ratonPosicionY+1][0]==1){
                                    mapa[ratonPosicionY+1][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(0,pixelCelda,pixelCelda,pixelCelda));
                                }else{
                                    mapa[ratonPosicionY+1][ratonPosicionX+1][1]->setTextureRect(sf::IntRect(pixelCelda,pixelCelda,pixelCelda,pixelCelda));
                                }
                            }
                        }
                    }
                    posX1=ratonPosicionX;
                    posY1=ratonPosicionY;


                }
            }

        }
    }
}

void Mapa::draw(sf::RenderWindow &window, bool onClick, float tick){
    for(int i=0;i<numCelda;i++){
        for(int j =0; j<numCelda;j++){
            if(mapa[i][j][0]!=NULL){
                window.draw(*(mapa[i][j][0]));
                //window.draw(*(mapa[i][j][1]));
            }

        }
    }
    if(posX1!=-1){
        if(elquedibujo==4){
            window.draw(*(mapa[posY1][posX1][1]));
        }else{
            window.draw(*(mapa[posY1][posX1][1]));
            window.draw(*(mapa[posY1+1][posX1][1]));
            window.draw(*(mapa[posY1][posX1+1][1]));
            window.draw(*(mapa[posY1+1][posX1+1][1]));
            
        }
    }
    menuLat->Actualiza(window,onClick);
    
}


Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
}

