#ifndef RPLIDAR_PROTOCOL_H_
#define RPLIDAR_PROTOCOL_H_

#include "../../Utilities/STD_TYPES.h"

//macros for command (CMD) operations

#define START_BIT				0xA5
#define CMD_STOP				0x25
#define CMD_RESET				0x40
#define CMD_SCAN				0x20
#define CMD_FORCE_SCAN			0x21
#define CMD_HQ_SCAN				0x83
#define CMD_GET_HEALTH			0x52
#define CMD_GET_SAMPLERATE		0x59
#define CMD_HQ_MOTOR_SPEED_CTR	0xA8
#define CMD_GET_INFO			0x50


// macros for descriptor check

#define ANS_SYNC_BYTE1		0xA5
#define ANS_SYNC_BYTE2		0x5A

//macros for  SCAN response packet

#define START_FLAG			1   //S bit
#define CHECK_BIT			1	//C bit

// macros for GET_HEALTH Response packet
#define RPLIDAR_STATUS_GOOD			0
#define RPLIDAR_STATUS_WARNING		1
#define RPLIDAR_STATUS_ERROR		2

#define MAX_MOTOR_PWM		1023
#define DEFAULT_MOTOR_PWM	660

typedef struct{
	float Angle_F;
	float Angle_B;
	float Angle_R;
	float Angle_L;
}angle_t;

typedef enum{
	OK=0,
	NOT_OK
}Check_t;
typedef struct
{
	float angle;
	float distance;
}Scan_Response_t;

#endif /* RPLIDAR_PROTOCOL_H_ */
