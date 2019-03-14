#include "IRsensor.hpp"
IRsen::IRsen(){
	 max_white=0;
 	 min_white=0;
  	 max_black=0;
  	 min_black=0;
  	 pin=A0;
}
IRsen::IRsen(int pin){
	init(pin);
}
//iniciacion de un pin
void IRsen::init(int pin){
	pin=A0;
	calibration();
}
//cuantas veces y que tan rapido se prende y apaga un led de referencia
void IRsen::stblink(int msec, int times){
	if(!times){
		digitalWrite(13,LOW);
  		digitalWrite(13,HIGH);
  		delay(msec);
	}
	else{
		int cont=0;
		while(cont<times){
					digitalWrite(13,LOW);
  					digitalWrite(13,HIGH);
  					delay(msec);
  					digitalWrite(13,LOW);
  			cont++;
		}	
	}
}
void IRsen::calibration(){
	int aux,cont=0;//variable auxiliar de guardado de datos y contador
	stblink(200,5); //cada 200 ms 5 veces
	aux=0;
	 max_white=aux;
 	 min_white=aux;
  	 max_black=aux;
  	 min_black=aux;
  	 while (cont<1000){
  	 	aux= analogRead(pin);
  		if(aux<min_white){
   			 min_white=aux;
  			}
 		 if(aux>max_white){
   			 max_white=aux;
  			}
  		cont++;
	   }
	cont=0;
	stblink(100,20); //cada 100 ms 20 veces dos segundos para cambiar de tono
	  	 while (cont<1000){
  	 	aux= analogRead(pin);
  		if(aux<min_black){
   			 min_black=aux;
  			}
 		 if(aux>max_black){
   			 max_black=aux;
  			}
  		cont++;
	   }
	stblink(200,10); //cada 200 ms 10 veces dos segundos para avisar que termino la calibracion 
		   	
}

//funcion de lectura de sensor regresa 0 en negro y 1 en blanco
int IRsen::st_read(){
	int ir_value=analogRead(pin);
  if(min_black<=ir_value&&ir_value<=max_black){
    return 0;
  }
  else if (min_white <= ir_value&&ir_value <= max_white){
    return 1;
  }
}
	


