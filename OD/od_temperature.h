/*
 * od_temperature.h
 *
 *  Created on: 7 déc. 2019
 *      Author: nicolasrabault
 */

#ifndef OD_OD_TEMPERATURE_H_
#define OD_OD_TEMPERATURE_H_

typedef float temperature_t;

// temperature are stored in degree celcius (°C)
//******** Conversions ***********

// °C
static inline float temperature_to_deg_c(temperature_t self)
{
    return self;
}

static inline temperature_t temperature_from_deg_c(float deg_c)
{
    return deg_c;
}

// °F
static inline float temperature_to_deg_f(temperature_t self)
{
    return self * 1.8f + 32.0f;
}

static inline temperature_t temperature_from_deg_f(float deg_f)
{
    return (deg_f - 32.0f) / 1.8f;
}

// °K
static inline float temperature_to_deg_k(temperature_t self)
{
    return self + 273.15f;
}

static inline temperature_t temperature_from_deg_k(float deg_k)
{
    return deg_k - 273.15f;
}

//******** Messages management ***********
static inline void temperature_to_msg(const temperature_t *const self, msg_t *const msg)
{
    msg->header.cmd = TEMPERATURE;
    memcpy(msg->data, self, sizeof(temperature_t));
    msg->header.size = sizeof(temperature_t);
}

static inline void temperature_from_msg(temperature_t *const self, const msg_t *const msg)
{
    memcpy(self, msg->data, msg->header.size);
}

static inline void reachy_arm_temp_to_msg(const temperature_t *const self, uint8_t nb_temp, msg_t *const msg)
{
    msg->header.cmd = REACHY_ARM_TEMP;
    memcpy(msg->data, self, sizeof(temperature_t) * nb_temp);
    msg->header.size = sizeof(temperature_t) * nb_temp;
}

#endif /* OD_OD_TEMPERATURE_H_ */
