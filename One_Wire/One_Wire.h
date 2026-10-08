#ifndef One_Wire_H_
#define One_Wire_H_

typedef struct {
	GPIO_TypeDef* 	port;
	uint16_t 		pin;
}ONEWIRE_PINOUT;

uint8_t ONEWIRE_Reset(ONEWIRE_PINOUT* onewire_pinout);


#endif
