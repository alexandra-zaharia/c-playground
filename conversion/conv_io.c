#include "conv_io.h"
#include "conversion.h"
#include <stdio.h>
#include <stdlib.h>

void do_menu() {
    printf("### Choice of temperature scale ###\n");
    printf("1 - Kelvin\n");
    printf("2 - Celsius\n");
    printf("3 - Fahrenheit\n");
    printf("Choose temperature scale to convert from (0 to quit): ");
}

int get_temp_scale() {
    int temp_scale; 
    
    do {
        do_menu();
        scanf("%d",&temp_scale);
        if (temp_scale == 0) {
            printf("### End of program ###\n");
            exit(EXIT_SUCCESS);
        }
    } while (!is_temp_scale_valid(temp_scale));
    
    return temp_scale;
}

int get_conv_scale(int temp_scale) {
    int conv_scale;
    
    do {
        printf("\n### Temperature scale to convert to ###\n");
        
        switch (temp_scale) {
            case KELVIN: {
                printf("2 - Celsius\n");
                printf("3 - Fahrenheit\n");
            }; break;
            case CELSIUS: {
                printf("1 - Kelvin\n");
                printf("3 - Fahrenheit\n");
            }; break;
            case FAHRENHEIT: {
                printf("1 - Kelvin\n");
                printf("2 - Celsius\n");
            }; break;
        }
        
        printf("Choose temperature scale to convert to: ");
        scanf("%d", &conv_scale);
    } while (!is_conv_scale_valid(temp_scale, conv_scale));
    
    return conv_scale;
}

char scale_to_char(int scale) {
    if (scale == KELVIN) return 'K';
    if (scale == CELSIUS) return 'C';
    if (scale == FAHRENHEIT) return 'F';
    return '?';
}

void display_result(
        double init, int scale_init, double final, int scale_final) {
    printf("\nA temperature of %.2f%c corresponds to %.2f%c.\n\n",
        init, scale_to_char(scale_init), final, scale_to_char(scale_final));
}
