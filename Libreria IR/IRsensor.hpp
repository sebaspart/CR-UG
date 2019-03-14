//libreria hecha por Sebastian Tovar Piña 13/03/19
//codigo para la adquisicion de un valor mediante un sensor CNY70 de contraste
// declaracion esperada IRsen nombre_variable(pin de entrada); 
//despues de esto se calibra, dando 5 blinks en el pin 13 de 200ms para blanco 
//20 blinks de 100ms para el cambio de contraste a negro o dos segundos para el cambio 
// 10 blinks de 100ms para indicar que termino la calibracion 
// st_read() devuelve 0 en negro y 1 en blanco
#ifndef IRSENSOR
#define IRSENSOR
#include <Arduino.h>
class IRsen {
  public:
  	//lectura de sensor
  int st_read();
  IRsen();
  //creacion de sensor con pin especifico
  IRsen(int pin);
  private:
  	 //inicialicacion
  	void init(int pin);
	void stblink(int msec, int times);
  void calibration();
  int pin;
  int max_white;
  int min_white;
  int max_black;
  int min_black;
};
#endif
