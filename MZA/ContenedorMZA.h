/* 
 * File:   ContenedorMZA.h
 * Author: Marta
 *
 * Created on 23 de abril de 2015, 20:33
 */

#ifndef CONTENEDORMZA_H
#define	CONTENEDORMZA_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

const std::string RUTA_SPRITES = "resources/Todo-Basic-581x498.png";

const std::string CASTILLO_NIVEL_1_A= "castillo1-A";
const std::string CASTILLO_NIVEL_2_A= "castillo2-A";
const std::string CASTILLO_NIVEL_3_A= "castillo3-A";
const std::string CASTILLO_NIVEL_1_B= "castillo1-B";
const std::string CASTILLO_NIVEL_2_B= "castillo2-B";
const std::string CASTILLO_NIVEL_3_B= "castillo3-B";
const std::string CASTILLO_NIVEL_1_C= "castillo1-C";
const std::string CASTILLO_NIVEL_2_C= "castillo2-C";
const std::string CASTILLO_NIVEL_3_C= "castillo3-C";

const int CASTILLO_VIDA_NIVEL_1 = 1500;
const int CASTLLO_VIDA_NIVEL_1_60 =  CASTILLO_VIDA_NIVEL_1*0.6;
const int CASTILLO_VIDA_NIVEL_1_30 =  CASTILLO_VIDA_NIVEL_1*0.3;
const int CASTILLO_MEJORAR_1= 300;
const int CASTILLO_MEJORAR_2= CASTILLO_MEJORAR_1*2;

const int CASTILLO_VIDA_NIVEL_2 = 3000;
const int CASTILLO_VIDA_NIVEL_2_60 =  CASTILLO_VIDA_NIVEL_2*0.6;
const int CASTILLO_VIDA_NIVEL_2_30 =  CASTILLO_VIDA_NIVEL_2*0.3;

const int CASTILLO_VIDA_NIVEL_3 = 4500;
const int CASTILLO_VIDA_NIVEL_3_60 =  CASTILLO_VIDA_NIVEL_3*0.6;
const int CASTILLO_VIDA_NIVEL_3_30 =  CASTILLO_VIDA_NIVEL_3*0.3;

const std::string MURO_NIVEL_1_A = "muro1-A";
const std::string MURO_NIVEL_1_B = "muro1-B";
const std::string MURO_NIVEL_1_C = "muro1-C";
const std::string MURO_NIVEL_2_A = "muro2-A";
const std::string MURO_NIVEL_2_B = "muro2-B";
const std::string MURO_NIVEL_2_C = "muro2-C";
const std::string MURO_NIVEL_3_A = "muro3-A";
const std::string MURO_NIVEL_3_B = "muro3-B";
const std::string MURO_NIVEL_3_C = "muro3-C";

const int MURO_VIDA_NIVEL_1 = 200;
const int MURO_VIDA_NIVEL_1_60 =  MURO_VIDA_NIVEL_1*0.6;
const int MURO_VIDA_NIVEL_1_30 =  MURO_VIDA_NIVEL_1*0.3;

const int MURO_PRECIO_NIVEL_1 = 20;
const int MURO_MEJORAR_1=MURO_PRECIO_NIVEL_1/4 ;
const int MURO_MEJORAR_2=MURO_PRECIO_NIVEL_1/2;


const int MURO_VIDA_NIVEL_2 = 400;
const int MURO_VIDA_NIVEL_2_60 =  MURO_VIDA_NIVEL_2*0.6;
const int MURO_VIDA_NIVEL_2_30 =  MURO_VIDA_NIVEL_2*0.3;

const int MURO_PRECIO_NIVEL_2 = 40;


const int MURO_VIDA_NIVEL_3 = 800;
const int MURO_VIDA_NIVEL_3_60 =  MURO_VIDA_NIVEL_3*0.6;
const int MURO_VIDA_NIVEL_3_30 =  MURO_VIDA_NIVEL_3*0.3;

const int MURO_PRECIO_NIVEL_3 = 80;

const std::string ARQUERO_NIVEL_1_A = "arquera1-A";
const std::string ARQUERO_NIVEL_1_B = "arquera1-B";
const std::string ARQUERO_NIVEL_1_C = "arquera1-C";
const std::string ARQUERO_NIVEL_2_A = "arquera2-A";
const std::string ARQUERO_NIVEL_2_B = "arquera2-B";
const std::string ARQUERO_NIVEL_2_C = "arquera2-C";
const std::string ARQUERO_NIVEL_3_A = "arquera3-A";
const std::string ARQUERO_NIVEL_3_B = "arquera3-B";
const std::string ARQUERO_NIVEL_3_C = "arquera3-C";


const int ARQUERO_VIDA_NIVEL_1 = 500;
const int ARQUERO_VIDA_NIVEL_1_60 =  ARQUERO_VIDA_NIVEL_1*0.6;
const int ARQUERO_VIDA_NIVEL_1_30 =  ARQUERO_VIDA_NIVEL_1*0.3;



const int ARQUERO_PRECIO_NIVEL_1 = 150;

const int ARQUERO_MEJORAR_1=ARQUERO_PRECIO_NIVEL_1/4 ;
const int ARQUERO_MEJORAR_2=ARQUERO_PRECIO_NIVEL_1/2;

const int ARQUERO_ATAQUE_NIVEL_1 = 10;
const int ARQUERO_CADENCIA_NIVEL_1 = 20;

const int ARQUERO_AREA_NIVEL_1 = 100;

const int ARQUERO_VIDA_NIVEL_2 = 1000;
const int ARQUERO_VIDA_NIVEL_2_60 =  ARQUERO_VIDA_NIVEL_2*0.6;
const int ARQUERO_VIDA_NIVEL_2_30 =  ARQUERO_VIDA_NIVEL_2*0.3;

const int ARQUERO_PRECIO_NIVEL_2 = 300;

const int ARQUERO_ATAQUE_NIVEL_2 = 20;
const int ARQUERO_CADENCIA_NIVEL_2 = 20;

const int ARQUERO_AREA_NIVEL_2 = 120;


const int ARQUERO_VIDA_NIVEL_3 = 2000;
const int ARQUERO_VIDA_NIVEL_3_60 =  ARQUERO_VIDA_NIVEL_3*0.6;
const int ARQUERO_VIDA_NIVEL_3_30 =  ARQUERO_VIDA_NIVEL_3*0.3;

const int ARQUERO_PRECIO_NIVEL_3 = 600;

const int ARQUERO_ATAQUE_NIVEL_3 = 30;
const int ARQUERO_CADENCIA_NIVEL_3 = 20;

const int ARQUERO_AREA_NIVEL_3 = 180;

const std::string CANON_NIVEL_1_A = "cañon1-A";
const std::string CANON_NIVEL_1_B = "cañon1-B";
const std::string CANON_NIVEL_1_C = "cañon1-C";
const std::string CANON_NIVEL_2_A = "cañon2-A";
const std::string CANON_NIVEL_2_B = "cañon2-B";
const std::string CANON_NIVEL_2_C = "cañon2-C";
const std::string CANON_NIVEL_3_A = "cañon3-A";
const std::string CANON_NIVEL_3_B = "cañon3-B";
const std::string CANON_NIVEL_3_C = "cañon3-C";

const int CANON_VIDA_NIVEL_1 = 500;
const int CANON_VIDA_NIVEL_1_60 =  CANON_VIDA_NIVEL_1*0.6;
const int CANON_VIDA_NIVEL_1_30 =  CANON_VIDA_NIVEL_1*0.3;

const int CANON_PRECIO_NIVEL_1 = 180;

const int CANON_MEJORAR_1=CANON_PRECIO_NIVEL_1/4 ;
const int CANON_MEJORAR_2=CANON_PRECIO_NIVEL_1/2;


const int CANON_ATAQUE_NIVEL_1 = 20;
const int CANON_CADENCIA_NIVEL_1 = 40;

const int CANON_AREA_NIVEL_1 = 140;

const int CANON_VIDA_NIVEL_2 = 1000;
const int CANON_VIDA_NIVEL_2_60 =  CANON_VIDA_NIVEL_2*0.6;
const int CANON_VIDA_NIVEL_2_30 =  CANON_VIDA_NIVEL_2*0.3;

const int CANON_PRECIO_NIVEL_2 = 360;

const int CANON_ATAQUE_NIVEL_2 = 40;
const int CANON_CADENCIA_NIVEL_2 = 40;

const int CANON_AREA_NIVEL_2 = 180;

const int CANON_VIDA_NIVEL_3 = 2000;
const int CANON_VIDA_NIVEL_3_60 =  CANON_VIDA_NIVEL_3*0.6;
const int CANON_VIDA_NIVEL_3_30 =  CANON_VIDA_NIVEL_3*0.3;

const int CANON_PRECIO_NIVEL_3 = 1080;

const int CANON_ATAQUE_NIVEL_3 = 80;
const int CANON_CADENCIA_NIVEL_3 = 40;

const int CANON_AREA_NIVEL_3 = 220;

const std::string MINA_NIVEL_1_A = "mina1-A";
const std::string MINA_NIVEL_1_B = "mina1-B";
const std::string MINA_NIVEL_1_C = "mina1-C";
const std::string MINA_NIVEL_2_A = "mina2-A";
const std::string MINA_NIVEL_2_B = "mina2-B";
const std::string MINA_NIVEL_2_C = "mina2-C";
const std::string MINA_NIVEL_3_A = "mina3-A";
const std::string MINA_NIVEL_3_B = "mina3-B";
const std::string MINA_NIVEL_3_C = "mina3-C";

const int MINA_VIDA_NIVEL_1 = 250;
const int MINA_VIDA_NIVEL_1_60 =  MINA_VIDA_NIVEL_1*0.6;
const int MINA_VIDA_NIVEL_1_30 =  MINA_VIDA_NIVEL_1*0.3;

const int MINA_PRECIO_NIVEL_1 = 50;

const int MINA_MEJORAR_1=MINA_PRECIO_NIVEL_1/4 ;
const int MINA_MEJORAR_2=MINA_PRECIO_NIVEL_1/2;

const int MINA_GENERACIONORO_NIVEL_1 = 1;

const int MINA_VIDA_NIVEL_2 = 500;
const int MINA_VIDA_NIVEL_2_60 =  MINA_VIDA_NIVEL_2*0.6;
const int MINA_VIDA_NIVEL_2_30 =  MINA_VIDA_NIVEL_2*0.3;

const int MINA_PRECIO_NIVEL_2 = 100;

const int MINA_GENERACIONORO_NIVEL_2 = 2;

const int MINA_VIDA_NIVEL_3 = 1000;
const int MINA_VIDA_NIVEL_3_60 =  MINA_VIDA_NIVEL_3*0.6;
const int MINA_VIDA_NIVEL_3_30 =  MINA_VIDA_NIVEL_3*0.3;

const int MINA_PRECIO_NIVEL_3 = 200;

const int MINA_GENERACIONORO_NIVEL_3 = 3;


const int WOLOLO_AUMENTOATAQUE_NIVEL_1 = 2;
const int WOLOLO_AUMENTOATAQUE_NIVEL_2 = 3;
const int WOLOLO_AUMENTOATAQUE_NIVEL_3 = 4;

const int WOLOLO_AUMENTOGENERACIONORO_NIVEL_1 = 2;
const int WOLOLO_AUMENTOGENERACIONORO_NIVEL_2 = 3;
const int WOLOLO_AUMENTOGENERACIONORO_NIVEL_3 = 4;

const int WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_1 = 2;
const int WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_2 = 3;
const int WOLOLO_AUMENTOCADENCIADISPARO_NIVEL_3 = 4;

//const int WOLOLO_TIEMPODURACION_NIVEL_1 = 5;
const int WOLOLO_TIEMPODURACION = 5;

typedef std::vector<std::string>  StringVector;
typedef std::vector<int>  IntVector;

StringVector Explode(const std::string & str );
IntVector coordenadasXML(std::string nombreEstructura);

#endif	/* CONTENEDORMZA_H */

