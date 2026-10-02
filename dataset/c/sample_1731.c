#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
} Vectorizer;

typedef struct {
    Vectorizer *vectorizer;
} DataProcessor;

typedef struct {
    DataProcessor *processor;
} MainLoop;

void vectorizer_init(Vectorizer *v, int size) {
    v->size = size;
}

double* generate_vector(Vectorizer *v) {
    double *vector = (double*)malloc(v->size * sizeof(double));
    for (int i = 0; i < v->size; i++) {
        vector[i] = (double)rand() / RAND_MAX;
    }
    return vector;
}

double* mutate_vector(Vectorizer *v, double *vector) {
    for (int i = 0; i < v->size; i++) {
        if ((double)rand() / RAND_MAX < 0.1) {
            vector[i] += (double)(rand() % 21 - 10) / 100;
        }
    }
    return vector;
}

void data_processor_init(DataProcessor *dp, Vectorizer *vectorizer) {
    dp->vectorizer = vectorizer;
}

void process_data(DataProcessor *dp) {
    double *data = generate_vector(dp->vectorizer);
    while (1) {
        double *mutated_data = mutate_vector(dp->vectorizer, data);
        free(data);
        data = mutated_data;
    }
}

void main_loop_init(MainLoop *ml, DataProcessor *processor) {
    ml->processor = processor;
}

void execute(MainLoop *ml) {
    process_data(ml->processor);
}

int main() {
    srand(time(NULL));
    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, 10);
    DataProcessor processor;
    data_processor_init(&processor, &vectorizer);
    MainLoop loop;
    main_loop_init(&loop, &processor);
    execute(&loop);
    return 0;
}