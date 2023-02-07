/*
 * OccupancyDetector.c
 *
 *  Created on: Jan 30, 2023
 *      Author: Modified By Nik Dimitrovski
 */
#include <msp430.h>


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    P1OUT &= ~BIT0;
    P1DIR |= BIT0;
    PM5CTL0 &= ~LOCKPLMS5;

    WDTCTL = WDTPW | WDTHOLD;
    P6OUT &= ~BIT6;
    P6DIR |= BIT6;
    PM5CTL0 &= ~LOCKPLMS5;

    P4REN |= BIT1;
    P4OUT |= BIT1;

    P6OUT ^= BIT6;

    while(1)
    {
        if (!(P4IN & BIT1))
        {
            unsigned int x_seconds=0;
            unsigned int totaltime=0;

            P1OUT ^= BIT0;
            P6OUT &= ~BIT6;
            __delay_cycles(500000);
        }
        else {
                P6OUT ^= BIT6;
                P1OUT &= ~BIT0;
                __delay_cycles(3000000);


        }


    }


}



