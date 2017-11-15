#ifndef UF_H
#define UF_H

typedef struct {
    int sites;   /* number of sites */
    int *parent; /* pointer to 1D array representing the parent of each site */
    int *weight; /* pointer to 1D array representing the weight of each site,
                    i.e. weight[i] represents the number of sites connected to
                    site i */
} configuration;

/* Creates, initializes and returns an initial configuration containing n sites
 * in which the parent of each site is the site itself and the weight of each
 * site is 1. */
configuration *initialize_configuration(int n);

/* Resets a given configuration (the parent of each site becomes the site itself
 * and the weight of each site is set to 1). */
void reset_configuration(configuration *config);

/* Frees up memory allocated to this configuration. */
void free_config(configuration *config);

/* Returns the root of a site p in the configuration config. If the parent of p
 * is a site other than p itself, then the parent of p is updated to become the
 * grandparent of p. */
int find(configuration *config, int p);

/* Returns 1 if sites p and q are connected in config, and 0 otherwise. */
int connected(configuration *config, int p, int q);

/* Connects sites p and q in config if their roots are different. In this case,
 * the parent of the "root" with the smaller weight is set to be the "root" with
 * the larger weight, and weights are updated accordingly. */
void do_union(configuration *config, int p, int q);

#endif /* UF_H */
