/*
 * main.C
 *
 *  Created on: Oct 26, 2017
 *      Author: Kyle Tam
 *      7-Segment display adder
 *      last Revised 10-26-17
 */
#include <msp430.h>
#include <msp430f5529.h>
#define BUTTON BIT1

void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   //Stop watchdog timer
    P1IE |= BUTTON;             //Enable Port1 interrupt on the button
    P1REN|= BUTTON;             //Enable Pullup Resistor
    P1OUT|= BUTTON;             //Set button to output

    _BIS_SR(LPM0_bits+GIE);     //Enter LMP0 and open all interrupts

}

#pragma vector=PORT1_VECTOR     // Set up interrupt vector
__interrupt void Port_1(void){
    P1IFG &= ~BUTTON;           // Clear interrupt flag

}
