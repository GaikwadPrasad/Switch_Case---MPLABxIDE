#include <xc.h>
#define _XTAL_FREQ 20000000

#include <stdio.h>
#include <stdlib.h>

void main() {
    
    TRISB = 0x00;  // PORTB as output
    TRISC = 0xFF;  // PORTC as input

    int mode = 0;

    while (1) {

        // Read inputs and determine mode
        if (PORTCbits.RC1 == 1 && PORTCbits.RC2 == 1) {
            mode = 1;
        } else if (PORTCbits.RC1 == 1 || PORTCbits.RC2 == 0) {
            mode = 2;
        } else if (PORTCbits.RC1 == 0 && PORTCbits.RC2 == 1) {
            mode = 3;
        } else if (!(PORTCbits.RC1 == 1 && PORTCbits.RC2 == 0)) {
            mode = 4;
        } else {
            mode = 0;
        }

        // Perform action based on mode
        switch (mode) {
            
            case 1:
                PORTBbits.RB1 = 1;
                PORTBbits.RB2 = 1;
                break;
                    
            case 2:
                PORTBbits.RB1 = 1;
                PORTBbits.RB2 = 0;
                break;
                 
            case 3:
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 1;
                break;
                
            case 4:
                PORTBbits.RB1 = 1;
                __delay_ms(1000);
                PORTBbits.RB2 = 1;
                __delay_ms(1000);
                break;
                
            default:
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 0;
                break;
        }
    }
}
