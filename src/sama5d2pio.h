#ifndef _SAMA5D2PIO_H_
#define _SAMA5D2PIO_H_

// Define the size that is mapped using nmap
#define MAPPED_SIZE     0x1000
// Define the start address of the IO port in memory
#define IO_PORT_RAM     0xFC038000

// Define the available registers of the IO port (reference: Atmel 11267)
#define PIO_MSKR        0x000
#define PIO_CFGR        0x004
#define PIO_PDSR        0x008
#define PIO_LOCKSR      0x00C
#define PIO_SODR        0x010
#define PIO_CODR        0x014
#define PIO_ODSR        0x018
#define PIO_IER         0x020
#define PIO_IDR         0x024
#define PIO_IMR         0x028
#define PIO_ISR         0x02C
#define PIO_IOFR        0x03C
#define PIO_WPMR        0x5E0
#define PIO_WPSR        0x5E4
#define OFFSET          0x40
// Config-register: Input (direction: input, pull-up enabled)
#define BCM2835_GPIO_FSEL_INPT  0x200u
// Config-register: Output (direction: output, pull-up enabled)
#define BCM2835_GPIO_FSEL_OUTP  0x100u
// This means pin HIGH, true, 3.3volts on a pin
#define HIGH 0x1
// This means pin LOW, false, 0volts on a pin
#define LOW  0x0


int bcm2835_init();
void bcm2835_cleanup();
void bcm2835_gpio_clr(uint8_t pin);
void bcm2835_gpio_set(uint8_t pin);
uint8_t bcm2835_gpio_lev(uint8_t pin);
void bcm2835_gpio_fsel(uint8_t pin, uint16_t mode);
void bcm2835_delayMicroseconds(uint64_t micros);
int* getreg(int off, int io_group);

#endif
