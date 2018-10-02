// File Name: keypad interface on 8051
// Author: R.venkatesan
// lcd 16X2 8bit method 
 // lcd pin connection port0 -data pin (D0-D7)
 // control pin lcd conection  RS=P2^7, R/W=P2^6, E=P2^5
 

# include <reg51.h>
# include <stdio.h>
# include "lcd.h"  // lcd library 
/* if want change the lcd pin connection open lcd file libary change the pin as per your aspect 
 And also remain you change busy flag= bf(used name in lcdlibrary ) also for inlcd pin data  lcd file libary  */
 # include "keypad.h" //keypad library pin connection Port1
 
 unsigned char password_check();
 char password[6]="ABC123"; // password using in this project
 void main()
 {
  port(); // pulldown the all pin in micro controller
	lcd_initial(); // lcd basic initialization cammand line 
	 while(1)
	 {
	   lcd_com(0x01);  // lcd cammand dispaly frist line
		 
		 lcd_string("keypad scan... "); 
		 
		 lcd_com (0xc0);  // lcd cammand dispaly second line
		 
		password_check();
//		 lcd_string("design by RV ");  
		 
		  delay(100); // delay for seen the lcd lines display
	 }
		 
 }
	 
 unsigned char password_check() // checking password
 {
	  ps_check();
				if(strncmp(ps1,password,6)==0)
				{
				lcd_com(0x01);
			 lcd_string("correct password");
					delay(100);
				}
				
			}