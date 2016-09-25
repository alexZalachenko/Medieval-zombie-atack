/* 
 * File:   ContenedorMZA.cpp
 * Author: Marta
 * 
 * Created on 23 de abril de 2015, 20:33
 */

#include "ContenedorMZA.h"

StringVector Explode(const std::string& str) {
   StringVector  result;
   size_t pos1 = 0;
   size_t pos2 = 0;
   while ( pos2 != str.npos )
   {
      pos2 = str.find("\"", pos1);
      if ( pos2 != str.npos )
      {
         if ( pos2 > pos1 )
            result.push_back( str.substr(pos1, pos2-pos1) );
         pos1 = pos2+1;
      }
   }
   result.push_back( str.substr(pos1, str.size()-pos1) );
   return result;
}

IntVector coordenadasXML(std::string nombreEstructura) {
std::ifstream in("resources/Todo-Basic-581x498.xml");
  std::string linea; 
  IntVector salida(4);

  while(std::getline(in, linea)){
      if(linea.find(nombreEstructura)!=std::string::npos){  
  
          StringVector miVector = Explode(linea);

          salida[0] = atoi( miVector[3].c_str() );
          salida[1] = atoi( miVector[5].c_str() );
          salida[2] = atoi( miVector[7].c_str() );
          salida[3] = atoi( miVector[9].c_str() );
          
          return salida;
      }
  }
  return salida;
}

