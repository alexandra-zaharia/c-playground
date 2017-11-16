#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "uf.h"

/* Creates and returns a configuration from the input file denoted by the string
 * 'filename'. The first line in the input file gives the number of sites, and
 * every other line contains two integers p and q separated by a space, meaning
 * sites p and q are connected in the configuration. */
configuration* connect_input(char *filename) {
    FILE *file_in;
    configuration *config;
    int n, p, q;

    /* Attempt to open the input file in read mode. */
    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        fprintf(stderr, "Cannot open '%s' for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Read the number of sites in the configuration. */
    if (fscanf(file_in, "%d", &n) != 1) {
        fprintf(stderr, "Unexpected input.\n");
        fclose(file_in);
        exit(EXIT_FAILURE);
    }

    /* Initialize the configuration. */
    config = initialize_configuration(n);
    if (config == NULL) {
        fprintf(stderr, "Configuration initialization failure. Aborting.\n");
        fclose(file_in);
        exit(EXIT_FAILURE);
    }

    /* Connect the sites according to the values in the input file. */
    while (fscanf(file_in, "%d %d", &p, &q) == 2)
        if (!connected(config, p, q))
            do_union(config, p, q);

    /* Close the input file. */
    fclose(file_in);

    /* Return the configuration. */
    return config;
}

/* For every site i in the configuration 'config', outputs to the output file
 * denoted by the string 'filename': the site i, the parent of site i, and the
 * weight of site i. The three values need to be on a single line and space-
 * separated. */
void connect_output(char *filename, configuration *config) {
    FILE *file_out;
    int i;

    /* Attempt to open the output file in write mode. */
    file_out = fopen(filename, "w");
    if (file_out == NULL) {
        fprintf(stderr, "Cannot open '%s' for writing.\n", filename);
        free(filename);
        free_config(config);
        exit(EXIT_FAILURE);
    }

    /* Print every site in order, its root and its weight to the output file,
     * one line per site. */
    for (i = 0; i < config->sites; i++)
        fprintf(
            file_out,
            "%d %d %d\n",
            i, find(config, i), config->weight[i]
        );

    /* Close the output file. */
    fclose(file_out);
}

/*
 * Main program taking 1 command-line argument giving the name of an input file
 * representing a configuration for union-find. The file is read, a 
 * configuration is created accordingly, and an output file is created 
 * containing every site in the configuration along with its parent and weight 
 * (one line per site, the three values being space-separated).
 *
 * Usage: ./uf_client /path/to/input.txt
 *
 * Output file: /path/to/input.txt.out
 *
 * Two input files are provided in data/, as follows:
 *     - test_case_small.txt  contains      10 sites
 *     - test_case_medium.txt contains     625 sites
 */
int main(int argc, char **argv) {
    char *filename_out = NULL;                     /* Name of the output file */
    configuration *config;

    if (argc != 2) {
        fprintf(stderr, "Expected 1 argument.\n");
        exit(EXIT_FAILURE);
    }

    /* Read the input file and connect sites accordingly. Retrieve the
     * configuration (number of sites, parent and weight 1D arrays). */
    config = connect_input(argv[1]);

    /* Allocate memory for the name of the output file. If the input file is
     * called 'input', the output file will be called 'input.out'. */
    filename_out = (char *)malloc((strlen(argv[1])+5) * sizeof(char));
    strcpy(filename_out, argv[1]);
    strcat(filename_out, ".out");

    /* Output every site in order, along with its root and weight, one line per
     * site. */
    connect_output(filename_out, config);

    /* Free allocated memory. */
    free(filename_out);
    free_config(config);
    
    return EXIT_SUCCESS;
}
