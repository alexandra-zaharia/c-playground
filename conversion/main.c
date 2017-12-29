#include "conversion.h"
#include "conv_io.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    double init_temp;  /* temperature to convert */

    for (;;) {
        /* temperature scale to convert from */
        int temp_scale = get_temp_scale(); 
        
        printf("\nEnter temperature to convert : ");
        scanf("%lf",&init_temp);

        /* temperature scale to convert to */
        int conv_scale = get_conv_scale(temp_scale);

        /* temperature after conversion */
        double conv_temp = do_conversion(temp_scale, conv_scale, init_temp);
        
        display_result(init_temp, temp_scale, conv_temp, conv_scale);
    }

    return EXIT_FAILURE; /* should never be reached */
}
