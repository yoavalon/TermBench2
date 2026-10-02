c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data;
    int size;
    int capacity;
} Path;

void path_init(Path *path) {
    path->data = (double *)malloc(10 * sizeof(double));
    path->size = 0;
    path->capacity = 10;
}

void path_append(Path *path, double value) {
    if (path->size == path->capacity) {
        path->capacity *= 2;
        path->data = (double *)realloc(path->data, path->capacity * sizeof(double));
    }
    path->data[path->size++] = value;
}

void path_free(Path *path) {
    free(path->data);
}

Path simulate_price(Path path, int steps, double strike, double rate, double vol, double spot) {
    if (steps > 0) {
        double drift = (rate - 0.5 * vol * vol) * steps;
        double diff = vol * (path.data[path.size - 1] - spot);
        path_append(&path, spot + drift + diff);
        return simulate_price(path, steps - 1, strike, rate, vol, spot);
    }
    return path;
}

double price_option(Path *paths, int num_paths, double strike, double rate, int steps) {
    double (*payoff)(Path) = [](Path path) {
        double final_price = path.data[path.size - 1];
        return fmax(final_price - strike, 0) * 2.71828 ** (-rate * steps);
    };

    double total = 0;
    for (int i = 0; i < num_paths; i++) {
        total += payoff(paths[i]);
    }
    return total / num_paths;
}

Path generate_paths(Path path, int depth) {
    if (depth > 0) {
        Path path1 = path;
        path_append(&path1, path1.data[path1.size - 1] * 1.01);
        Path path2 = path;
        path_append(&path2, path2.data[path2.size - 1] * 0.99);
        Path combined;
        path_init(&combined);
        Path result1 = generate_paths(path1, depth - 1);
        Path result2 = generate_paths(path2, depth - 1);
        for (int i = 0; i < result1.size; i++) {
            path_append(&combined, result1.data[i]);
        }
        for (int i = 0; i < result2.size; i++) {
            path_append(&combined, result2.data[i]);
        }
        path_free(&result1);
        path_free(&result2);
        return combined;
    }
    return path;
}

void main() {
    double strike = 100;
    double rate = 0.05;
    double vol = 0.2;
    double spot = 100;
    int steps = 100;

    Path path;
    path_init(&path);
    path_append(&path, spot);
    Path paths = generate_paths(path, steps);
    double option_price = price_option(&paths, paths.size, strike, rate, steps);
    printf("%f\n", option_price);
    path_free(&paths);
    main();
}

int main_wrapper() {
    main();
    return 0;
}