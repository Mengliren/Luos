/*
 * od_angular.h
 *
 *  Created on: 6 déc. 2019
 *      Author: nicolasrabault
 */

#ifndef OD_OD_ANGULAR_H_
#define OD_OD_ANGULAR_H_

typedef float angular_position_t;

// angular_position are stored in degree (deg)
//******** Conversions ***********

// deg
static inline float angular_position_to_deg(angular_position_t self)
{
    return self;
}

static inline angular_position_t angular_position_from_deg(float deg)
{
    return deg;
}

// rev
static inline float angular_position_to_rev(angular_position_t self)
{
    return self / 360.0f;
}

static inline angular_position_t angular_position_from_rev(float rev)
{
    return rev * 360.0f;
}

// rad
static inline float angular_position_to_rad(angular_position_t self)
{
    return (self * 2.0f * 3.141592653589793f) / 360.0f;
}

static inline angular_position_t angular_position_from_rad(float rad)
{
    return (rad * 360.0f) / (2.0f * 3.141592653589793f);
}

//******** Messages management ***********
static inline void angular_position_to_msg(const angular_position_t *const self, msg_t *const msg)
{
    msg->header.cmd = ANGULAR_POSITION;
    memcpy(msg->data, self, sizeof(angular_position_t));
    msg->header.size = sizeof(angular_position_t);
}

static inline void angular_position_from_msg(angular_position_t *const self, const msg_t *const msg)
{
    memcpy(self, msg->data, msg->header.size);
}

static inline void reachy_arm_pos_to_msg(const angular_position_t *const self, uint8_t nb_pos, msg_t *const msg)
{
    msg->header.cmd = REACHY_ARM_POS;
    memcpy(msg->data, self, sizeof(angular_position_t) * nb_pos);
    msg->header.size = sizeof(angular_position_t) * nb_pos;
}

typedef float angular_speed_t;

// angular_speed are stored in degree/s (deg/s)
//******** Conversions ***********

// deg_s
static inline float angular_speed_to_deg_s(angular_speed_t self)
{
    return self;
}

static inline angular_speed_t angular_speed_from_deg_s(float deg)
{
    return deg;
}

// rev_s
static inline float angular_speed_to_rev_s(angular_speed_t self)
{
    return self / 360.0f;
}

static inline angular_speed_t angular_speed_from_rev_s(float rev_s)
{
    return rev_s * 360.0f;
}

// rev_min
static inline float angular_speed_to_rev_min(angular_speed_t self)
{
    return self * 60.0f / 360.0f;
}

static inline angular_speed_t angular_speed_from_rev_min(float rev_min)
{
    return rev_min * 360.0f / 60.0f;
}

// rad_s
static inline float angular_speed_to_rad_s(angular_speed_t self)
{
    return (self * 2.0f * 3.141592653589793f) / 360.0f;
}

static inline angular_speed_t angular_speed_from_rad_s(float rad_s)
{
    return (rad_s * 360.0f) / (2.0f * 3.141592653589793f);
}

//******** Messages management ***********
static inline void angular_speed_to_msg(const angular_speed_t *const self, msg_t *const msg)
{
    msg->header.cmd = ANGULAR_SPEED;
    memcpy(msg->data, self, sizeof(angular_speed_t));
    msg->header.size = sizeof(angular_speed_t);
}

static inline void angular_speed_from_msg(angular_speed_t *const self, const msg_t *const msg)
{
    memcpy(self, msg->data, msg->header.size);
}

#endif /* OD_OD_ANGULAR_H_ */
