#include "conversion.h"
#include "conv_io.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int temp_scale;    /* temperature scale to convert from */
    int conv_scale;    /* temperature scale to convert to */
    
    double init_temp;  /* temperature to convert */
    double conv_temp;  /* temperature after conversion */

    for (;;) {
        temp_scale = get_temp_scale();
        
        printf("\nEnter temperature to convert : ");
        scanf("%lf",&init_temp);

        conv_scale = get_conv_scale(temp_scale);

        conv_temp = do_conversion(temp_scale, conv_scale, init_temp);
        
        display_result(init_temp, temp_scale, conv_temp, conv_scale);
    }

    return EXIT_FAILURE;  /* should never be reached */
}
