/* 
 * File:   contenedorCastillo.h
 * Author: Marta
 *
 * Created on 22 de marzo de 2015, 21:03
 */

#ifndef CONTENEDORCASTILLO_H
#define	CONTENEDORCASTILLO_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

const std::string RUTA_SPRITES = "resources/Todo-Basic-581x498.png";

const std::string CASTILLO_NIVEL_1= "castillo1-A";
const std::string CASTILLO_NIVEL_2= "castillo2-A";
const std::string CASTILLO_NIVEL_3= "castillo3-A";

const int CASTILLO_VIDA_NIVEL_1 = 1500;
const int CASTLLO_VIDA_NIVEL_1_60 =  CASTILLO_VIDA_NIVEL_1*0.6;
const int CASTILLO_VIDA_NIVEL_1_30 =  CASTILLO_VIDA_NIVEL_1*0.3;

const int CASTILLO_VIDA_NIVEL_2 = 3000;
const int CASTILLO_VIDA_NIVEL_2_60 =  CASTILLO_VIDA_NIVEL_2*0.6;
const int CASTILLO_VIDA_NIVEL_2_30 =  CASTILLO_VIDA_NIVEL_2*0.3;



const int CASTILLO_VIDA_NIVEL_3 = 4500;
const int CASTILLO_VIDA_NIVEL_3_60 =  CASTILLO_VIDA_NIVEL_3*0.6;
const int CASTILLO_VIDA_NIVEL_3_30 =  CASTILLO_VIDA_NIVEL_3*0.3;


typedef std::vector<std::string>  StringVector;
typedef std::vector<int>  IntVector;

//StringVector Explode(const std::string & str );
//IntVector coordenadasXML(std::string nombreEstructura);



#endif	/* CONTENEDORCASTILLO_H */

