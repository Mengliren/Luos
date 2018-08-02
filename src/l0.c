#include "l0.h"

int l0_msg_handler(vm_t* vm, msg_t* input, msg_t* output) {

	  if (input->header.cmd == L0_LED) {
		  if (input->data[0] < 2) {
			  HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin, (input->data[0] == 0));
			  return LUOS_PROTOCOL_NB;
		  }
	  }
	  if (input->header.cmd == L0_TEMPERATURE) {
	      output->header.cmd = L0_TEMPERATURE;
	      output->header.target_mode = ID;
	      output->header.size = sizeof(float);
	      output->header.target = input->header.source;
	      //float temp = ((110.0f - 30.0f) / ((float)(*TEMP110_CAL_VALUE) - (float)(*TEMP30_CAL_VALUE)) * ((float)L0_analog.temperature_sensor - (float)(*TEMP30_CAL_VALUE)) + 30.0f);

		  float temp;
	      temp = (((float)L0_analog.temperature_sensor * 300.0f / 330.0f) - (float)(*TEMP30_CAL_VALUE) );
	      temp = temp * (110.0f - 30.0f);
	      temp = temp /(float)(*TEMP110_CAL_VALUE - *TEMP30_CAL_VALUE);
	      temp = temp + 30.0f;

	      memcpy(output->data, &temp, sizeof(float));
	      return L0_TEMPERATURE;
	   }
	  if (input->header.cmd == L0_VOLTAGE) {
	      output->header.cmd = L0_VOLTAGE;
	      output->header.target_mode = ID;
	      output->header.size = sizeof(float);
	      output->header.target = input->header.source;
	      float volt = (((float)L0_analog.voltage_sensor * 3.3f) / 4096.0f) * VOLTAGEFACTOR;
	      memcpy(output->data, &volt, sizeof(float));
	      return L0_VOLTAGE;
	   }
	  return LUOS_PROTOCOL_NB;
}