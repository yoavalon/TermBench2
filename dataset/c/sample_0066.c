#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double permute_pvalue(int *data, int data_size, int perm_count) {
    double obs_stat = 0.0;
    for (int i = 0; i < data_size; i++) {
        obs_stat += data[i];
    }
    obs_stat /= data_size;

    double perm_stats[perm_count];
    for (int i = 0; i < perm_count; i++) {
        int perm_data[data_size];
        for (int j = 0; j < data_size; j++) {
            perm_data[j] = data[j];
        }

        for (int j = 0; j < data_size; j++) {
            int idx = rand() % data_size;
            int temp = perm_data[j];
            perm_data[j] = perm_data[idx];
            perm_data[idx] = temp;
        }

        double perm_stat = 0.0;
        for (int j = 0; j < data_size; j++) {
            perm_stat += perm_data[j];
        }
        perm_stat /= data_size;
        perm_stats[i] = perm_stat;
    }

    int count = 0;
    for (int i = 0; i < perm_count; i++) {
        if (perm_stats[i] >= obs_stat) {
            count++;
        }
    }

    return (double)count / perm_count;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int data_size = sizeof(data) / sizeof(data[0]);
    int perm_count = 1000;
    srand(time(0));
    double result = permute_pvalue(data, data_size, perm_count);
    printf("%f\n", result);
    return 0;
}