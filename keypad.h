 # include <reg51.h>
# include<string.h>
#define keypad P1

sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;

char ps1[6];


unsigned char scan_keypad()
 {
keypad=0xf0;

	while(keypad==0xf0)
	{
		continue;
	}
	
keypad=0xfe;
	if(c0==0) return ('1');
	if(c1==0) return ('2');
	if(c2==0) return ('3');
	if(c3==0) return ('A');
	
keypad=0xfd;
	if(c0==0) return ('4');
	if(c1==0) return ('5');
	if(c2==0) return ('6');
	if(c3==0) return ('B');
	
	keypad=0xfb;
	if(c0==0) return ('7');
	if(c1==0) return ('8');
	if(c2==0) return ('9');
	if(c3==0) return ('C');
	
	keypad=0xf7;
	if(c0==0) return ('*');
	if(c1==0) return ('0');
	if(c2==0) return ('#');
	if(c3==0) return ('D');
 }
 
 unsigned char ps_check()
 {
	 int i;
	 for(i=0;i<6;i++)
	{
		 ps1[i]=scan_keypad();
		 lcd_data('*');
		 delay(80);
   }
 return (ps1);
 }
 
 
 
