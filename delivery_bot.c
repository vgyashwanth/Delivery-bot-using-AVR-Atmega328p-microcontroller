/*ir sensor output
ouput high-no refelection
output low-reflection happen*/


#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000UL
int monitor_after_unload(void);
int stop(void);
int start(void);
int stop_for_unload(void);
int stop_for_next_load(void);
int move_some_distance(void);
int begin_the_show(void);
int main(void){
DDRD=0XFF;//0b11111111
DDRB=0X00;
DDRC=0X00;
PORTC=0XFF;
PORTB=0XFF;
while(1){
  
  begin_the_show();
  
  }

 

return 0;
}
int stop(void){
    PORTD=0X00;
    return 0;
}
int move_some_distance(void){
    int i;
PORTD=0b00001010;
for(i=0;i<=3;i++){
_delay_ms(1000);}
return 0;

}
int start(void){
  int monitor;
while(1){monitor=PINB&(0x0F);
switch(monitor){
  case 3:
  PORTD=0b00001001;
  break;
  case 2:
  PORTD=0b00000001;
  break;
  case 1:
  PORTD=0b00001000;
  break;
  case 15:
  PORTD=0b00000000;
  stop_for_unload();
  break;
  default:
  PORTD=0b00000000;
  break;
  }}

         
    return 0; }

 int stop_for_unload(void){
 PORTD=0b00100000;
 _delay_ms(3000);
 PORTD=0b00010000;
 _delay_ms(3000);
 PORTD=0b00000000;
  int load_status;
  load_status=PINC&(0x01);
  if(load_status==1){
    _delay_ms(2000);
    move_some_distance();
    monitor_after_unload();
    
    }
  else{

    stop();
    
    }
  
  
  
  return 0;
  }
int monitor_after_unload(){
  int monitor;
  while(1){
    monitor=PINB&(0x0F);
switch(monitor){
  case 3:
  PORTD=0b00001001;
  break;
  case 2:
  PORTD=0b00000001;
  break;
  case 1:
  PORTD=0b00001000;
  break;
  case 15:
  PORTD=0b00000000;
  stop_for_next_load();
  break;
  default:
  PORTD=0b00000000;
  break;
  }}
  
  return 0;
  }

int stop_for_next_load(void){
  
  int load_status;
   load_status=PINC&(0x01);
if(load_status==0){
  _delay_ms(2000);
  move_some_distance();
  start();
  }
  else{
    stop();
    
    }
  
 return 0; 
  }

int begin_the_show(void){
  
  stop_for_next_load();
  return 0;
  
  
  }
