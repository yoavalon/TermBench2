#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int data_size;
    int result;
} OptimizationModel;

void OptimizationModel_init(OptimizationModel *self, int *data, int data_size) {
    self->data = data;
    self->data_size = data_size;
    self->result = 0;
}

int analyze_item(int item) {
    if (item % 2 == 0) {
        return item * 2;
    } else {
        return item * 3;
    }
}

void OptimizationModel_process_data(OptimizationModel *self) {
    for (int i = 0; i < self->data_size; i++) {
        self->result += analyze_item(self->data[i]);
    }
}

typedef struct {
    int index;
} DataGenerator;

void DataGenerator_init(DataGenerator *self) {
    self->index = 0;
}

int DataGenerator_generate(DataGenerator *self) {
    return self->index++;
}

typedef struct {
    DataGenerator generator;
    OptimizationModel model;
} Controller;

void Controller_init(Controller *self) {
    DataGenerator_init(&self->generator);
    OptimizationModel_init(&self->model, NULL, 0);
}

void Controller_run(Controller *self) {
    int data[10];
    while (1) {
        for (int i = 0; i < 10; i++) {
            data[i] = DataGenerator_generate(&self->generator);
        }
        OptimizationModel_init(&self->model, data, 10);
        OptimizationModel_process_data(&self->model);
        printf("%d\n", self->model.result);
    }
}

int main() {
    Controller controller;
    Controller_init(&controller);
    Controller_run(&controller);
    return 0;
}