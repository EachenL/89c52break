#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit wela = P2^7;
sbit dula = P2^6;
sbit d1 = P1^0;
unsigned code leddata[]={0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d ,0x07, 0x7f};
unsigned code led[]={0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
uint num;
uint a;
void delay(uint z)
{
	for (; z>0; z--);
}
void main()
{
	EA = 1;
	EX0 = 1;
	IT0 = 0;
	

	while (1)
	{	
		num = 0;
				
		while (num<8)
		{	
			d1=1;
			wela = 1;
			P0 = led[num];
			wela = 0;
			dula = 1;
			P0 = leddata[num];
			dula = 0;
			num++;
			delay(20000);
		}

	}
	
}
void exter0() interrupt 0
{
	d1 = 0;
}
