#include <LPC213x.H>

// Software delay routine
void delay_ms(volatile unsigned int count) {
    volatile unsigned int i;
    for (i = 0; i < count * 50; i++) {
        __asm("NOP");
    }
}

int main(void) {
    // Set Pin P0.10 and Pin P0.11 as Outputs using Legacy GPIO
    IODIR0 |= (1 << 10) | (1 << 11);

    while (1) {
        // Turn ON P0.11 (Heartbeat LED)
        IOSET0 = (1 << 11);
        delay_ms(250);

        // Turn OFF P0.11
        IOCLR0 = (1 << 11);
        delay_ms(250);
    }
}