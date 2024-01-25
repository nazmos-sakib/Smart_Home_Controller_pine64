#ifndef ADC_H
#define ADC_H

// ADC definitions
#define ADC_GAIN1 ADC_PGA_GAIN_1
#define ADC_GAIN2 ADC_PGA_GAIN_1

// must be between 500 and 16,000
#define ADC_FREQUENCY 4096
#define NUMBER_OF_SAMPLES 1024

#define SINGLE_CHANNEL_CONVERSION_MODE 1

#define ADC_PIN 4


/* function prototypes (needed for compiler, functions are implemented below) */
void init_adc(uint8_t pin);
uint32_t read_adc();
void convert_to_binary(uint32_t n);

#endif