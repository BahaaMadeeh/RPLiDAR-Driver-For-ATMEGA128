/*
 * RPLIDAR.h
 *
 * Created: 5/5/2023 12:56:34 AM
 *  Author: Bahaa
 */ 


#ifndef RPLIDAR_H_
#define RPLIDAR_H_

#include "../Utilities/STD_TYPES.h"
#include "../MCAL/UART/UART.h"
#include "rplidar_protocol.h"
#include "rptypes.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../Utilities/Registers.h"
#include <util/delay.h>

	
void scan_response(float angle1, float angle2);
Check_t get_health(void);
void Descriptor_Check(void);


#endif /* RPLIDAR_H_ */