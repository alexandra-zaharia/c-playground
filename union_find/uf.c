#include "uf.h"
#include <stdlib.h>

/* Creates, initializes and returns an initial configuration containing n sites
 * in which the parent of each site is the site itself and the weight of each
 * site is 1. */
configuration *initialize_configuration(int n) {
    configuration *config = (configuration *)malloc(sizeof(configuration));

    config->sites = n;
    config->parent = (int *)malloc(n * sizeof(int));
    config->weight = (int *)malloc(n * sizeof(int));
    reset_configuration(config);

    return config;
}

/* Resets a given configuration (the parent of each site becomes the site itself
 * and the weight of each site is set to 1). */
void reset_configuration(configuration *config) {
    int i;
    
    for (i = 0; i < config->sites; i++) {
        config->parent[i] = i;
        config->weight[i] = 1;
    }
}

/* Frees up memory allocated to this configuration. */
void free_config(configuration *config) {
    free(config->parent);
    free(config->weight);
    free(config);
}

/* Returns the root of a site p in the configuration config. If the parent of p
 * is a site other than p itself, then the parent of p is updated to become the
 * grandparent of p. */
int find(configuration *config, int p) {
    while (p != config->parent[p]) {
        config->parent[p] = config->parent[config->parent[p]];
        p = config->parent[p];
    }
    return p;
}

/* Returns 1 if sites p and q are connected in config, and 0 otherwise. */
int connected(configuration *config, int p, int q) {
    return find(config, p) == find(config, q);
}

/* Connects sites p and q in config if their roots are different. In this case,
 * the parent of the "root" with the smaller weight is set to be the "root" with
 * the larger weight, and weights are updated accordingly. */
void do_union(configuration *config, int p, int q) {
    int root_p, root_q;
    
    root_p = find(config, p);
    root_q = find(config, q);

    if (root_p != root_q) {
        if (config->weight[root_p] < config->weight[root_q]) {
            config->parent[root_p] = root_q;
            config->weight[root_q] += config->weight[root_p];
        } else {
            config->parent[root_q] = config->parent[root_p];
            config->weight[root_p] += config->weight[root_q];
        }
    }
}
