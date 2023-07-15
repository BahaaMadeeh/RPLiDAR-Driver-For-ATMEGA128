/*
 * RPLIDAR.c
 *
 * Created: 5/5/2023 12:58:15 AM
 *  Author: Bahaa
 */ 

#include "RPLIDAR.h"

	uint8 dis[7] = { 0xa5, 0x5a, 0x05, 0x00, 0x00, 0x40, 0x81 };
	uint8 Scan_Descriptor[7] = { 0 };
	uint8 voice;
	uint8 Flag = 0,sharp_flag=0;
	float Angle=0,Distance=0;

/*	Scan Response function, takes the angle range to scan	*/

void scan_response(float angle1, float angle2)
{

	uint8 response[5]={0};
	uint8 c=1;
	uint8 AngleL, AngleH, DistanceL, DistanceH;

		uint8 i=0;
		
	if(Flag == 0)
	{
		while(1)
		{
			response[0]=0;
			response[1]=0;
			response[2]=0;
			response[3]=0;
			response[4]=0;
			response[0]=USART_Recieve(UART1);
			/*	the first byte must be 0x3E, otherwise the data is wrong	*/
			while (response[0] != 0x3E)
			{
				response[0]=USART_Recieve(UART1);
			}
              c=1;
				for(i=1; i<5; i++)
				{
					response[i]=USART_Recieve(UART1);
					c++;

				}
			/*	If the 4th and 5th byte are zeros, RPLiDAR didn't scan correctly (zero distance) 	*/
			
			if((response[0] == 0x3E && (response[3]!=0x00 && response[4]!=0x00)))
			{
				/*processing data*/
				
				/*	If any byte except the first is 0x3E, A byte is lost during transmission (Error)*/
				
				if(response[0] == 0x3E && ((response[4]!=0x3E) || (response[3]!=0x3E) || (response[2]!=0x3E) || (response[1]!=0x3E)))
				{
					AngleL = response[1];
					AngleH = response[2];
					DistanceL = response[3];
					DistanceH = response[4];
					Angle = (float)(((AngleH << 7) | (AngleL >> 1))/64.0);		//Actual Angle Correction Equation
					Distance = (float)(((DistanceH << 8) | (DistanceL))/4.0);	//Actual Distance Correction Equation

					if(angle1 >= 0 && angle2<=45)
					{
						if((Angle >= angle1 && Angle <= angle2) || (Angle >= 315.0 && Angle < 360.0))
						{
							break;
						}
					}
				   if((Angle >= angle1 && Angle <= angle2))
					{
						break;
					}

				}
			}
		}
	}
	}
	
Check_t get_health(void)
	{
		unsigned int k=0;
		uint8 health[10]={0};
		Check_t check = OK;

		USART_Transmit(UART1, START_BIT);
		USART_Transmit(UART1, CMD_GET_HEALTH);
		
		for(k=0; k<10 ; k++)
		{
			health[k] = USART_Recieve(UART1);
		}
		
		/*	the 8th byte must be 0x00, otherwise we have to reset RPLiDAR */
		if(health[7] != 0x00)
		{
			USART_Transmit(UART1,START_BIT);
			USART_Transmit(UART1,CMD_RESET);
			_delay_ms(2);
			check= NOT_OK;
		}

		return check;
	}
	
	void Descriptor_Check(void)
	{
		 /*  Receive the Descriptor of Scan Request from RPLIDAR	*/
		 
		 for(int i=0; i<7;i++)
		 {
			 Scan_Descriptor[i]=USART_Recieve(UART1);
		 }

		 /* Check If the Descriptor is Valid	*/
		 
		 for(int i=0;i<7;i++)
		 {
			 if(Scan_Descriptor[i] != dis[i])
			 {
				 Flag=1;
			 }
		 }
	}
	
