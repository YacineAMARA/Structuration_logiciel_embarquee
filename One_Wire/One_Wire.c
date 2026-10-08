#include "One_Wire.h"

uint8_t ONEWIRE_Reset(ONEWIRE_PINOUT* onewire_pinout)
{
	uint8_t presence = 0;
	GPIO_ResetPin(onewire_pinout->port,onewire_pinout-> pin);
	delay_us(480);
	GPIO_SetPin(onewire_pinout->port,onewire_pinout-> pin);
	delay_us(70);
	presence = !(GPIO_ReadPin(onewire_pinout->port,onewire_pinout-> pin));
	delay_us(410);
	return presence;
}
