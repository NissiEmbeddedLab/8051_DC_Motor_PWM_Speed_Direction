#include<reg51.h>
sbit m1p = P2^0;
sbit m1n = P2^1;
sbit m2p = P2^2;
sbit m2n = P2^3;
sbit m1s = P2^4;
sbit m2s = P2^5;
void T0M1Delay(unsigned int x);
unsigned int t;
void main(void)
{
	while(1)
	{
		m1p = 1;     //Motor1,2 Anticlockwise
		m1n = 0;
		m2p = 0;
		m2n = 1;
	T0M1Delay(250);
		m1p = 0;     //Motor1,2 off
		m1n = 0;
		m2p = 0;
		m2n = 0;
		T0M1Delay(50);
	m1p = 0; 				//Motor 1,2 Clockwise
		m1n = 1;
		m2p = 1;
		m2n = 0;
		
	T0M1Delay(250);
		m1p = 0;     //Motor1,2 off
		m1n = 0;
		m2p = 0;
		m2n = 0;
		T0M1Delay(50);
		m1p = 1;     //Motor1,2 Anticlockwise
		m1n = 0;
		m2p = 0;
		m2n = 1;
		for(t=0;t<20;t++) // Motor 1,2 Anticlockwise with slow speed
		{
			m1s = 1;
			m2s = 1;
			T0M1Delay(5);
			m1s = 0;
			m2s = 0;
			T0M1Delay(15);
		}
		m1p = 0;     //Motor1,2 off
		m1n = 0;
		m2p = 0;
		m2n = 0;
		T0M1Delay(50);
		m1p = 0; 				//Motor 1,2 Clockwise
		m1n = 1;
		m2p = 1;
		m2n = 0;
		for(t=0;t<20;t++) // Motor 1,2 Anticlockwise with slow speed
		{
			m1s = 1;
			m2s = 1;
			T0M1Delay(5);
			m1s = 0;
			m2s = 0;
			T0M1Delay(15);
		}
		m1p = 0;     //Motor1,2 off
		m1n = 0;
		m2p = 0;
		m2n = 0;
		T0M1Delay(50);
	}
}
void T0M1Delay(unsigned int x) //function to create 10msec delay 
{
	unsigned int a;
	for(a=0;a<x;a++)
	{
	TMOD = 0x01;
	TH0 = 0xD8; 			//0XD8F0 FOR 10msec delay @12MHz Oscillator frquency
	TL0 = 0xF0;
	TR0 = 1;
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
	}
}