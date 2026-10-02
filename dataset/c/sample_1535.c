#include <stdio.h>
#include <stdlib.h>

void data_mutations() {
    void update_velocity(double *p, double *v, double *g, double *l, double *new_v, int size) {
        for (int i = 0; i < size; i++) {
            new_v[i] = v[i] + 0.7 * (p[i] - v[i]) + 1.5 * (g[i] - v[i]) + 0.5 * (l[i] - v[i]);
        }
    }

    void update_position(double *x, double *v, double *new_x, int size) {
        for (int i = 0; i < size; i++) {
            new_x[i] = x[i] + v[i];
        }
    }

    void optimize() {
        double p[2] = {0.1, 0.2};
        double g[2] = {0.1, 0.3};
        double l[2] = {0.2, 0.4};
        double v[2] = {0.01, 0.02};
        double new_v[2];
        double new_p[2];

        while (1) {
            update_velocity(p, v, g, l, new_v, 2);
            update_position(p, v, new_p, 2);
            for (int i = 0; i < 2; i++) {
                if (new_p[i] > g[i]) {
                    g[i] = new_p[i];
                }
                if (new_p[i] < l[i]) {
                    l[i] = new_p[i];
                }
                p[i] = new_p[i];
                v[i] = new_v[i];
            }
        }
    }

    optimize();
}

int main() {
    data_mutations();
    return 0;
}