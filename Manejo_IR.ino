int ir_sensor=A0; //puerto de la seÃ±al de entrada del sensor
//led para sensado de blanco en puerto digital 12 y led para sensado negro en puerto digital 11
int ir_value,ir_max_white,ir_min_white,ir_max_black,ir_min_black,led_white=12,led_black=11;
int ir_med (int sensor);
void setup() {
  //valores auxiliares para mediciÃ³n
  int med_aux,i=0;
 
  pinMode(led_white,OUTPUT);
  pinMode(led_black,OUTPUT);
  digitalWrite(led_white,HIGH);
  delay(2000);
  /* establecimiento de maximos y minimos de la seÃ±al obtenida en
   *  blanco, para un margen de valores a obtener que sean aceptados
   *  como tono blanco del sensor
   *  donde en la funcion ir_med() se hace la medicion y se da un tiempo de
   *  5ms dando asÃ­ 500ms de muestra por sensor y 1 segundo para cambiar
   *  de color negro a blanco, donde los leds indican cual es el color
   *  que se estÃ¡ evaluando
   */
  ir_min_white=ir_med(ir_sensor);
  ir_max_white=ir_min_white; //variable base
  while (i<1000){
  med_aux= ir_med(ir_sensor);
  if(med_aux<ir_min_white){
    ir_min_white=med_aux;   //reasignacion de menor
  }
  if(med_aux>ir_max_white){
    ir_max_white=med_aux;   //reasignacion de mayor
  }
  i++;
  }
  i=0;
  digitalWrite(led_white,LOW);
  digitalWrite(led_black,HIGH);
  delay(2000);
  ir_min_black=ir_med(ir_sensor);
  ir_max_black=ir_min_black;
  while (i<1000){
  med_aux= ir_med(ir_sensor);
  if(med_aux<ir_min_black){
    ir_min_black=med_aux;
  }
  if(med_aux>ir_max_black){
    ir_max_black=med_aux;
  }
  i++;
  }
  i=0;
  digitalWrite(led_black,LOW);
  delay(1000);
}

void loop() {
  ir_value=ir_med(ir_sensor);
  if(ir_min_black<=ir_value&&ir_value<=ir_max_black){
    digitalWrite(led_black,HIGH);
    digitalWrite(led_white,LOW);
  }
  else if (ir_min_white <= ir_value&&ir_value <= ir_max_white){
    digitalWrite(led_black,LOW);
    digitalWrite(led_white,HIGH);
  }
  
}
int ir_med (int sensor){
  int value=analogRead(sensor);
  delay(5);
  return value;
}

