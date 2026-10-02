#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Coordinate;

typedef struct {
    Coordinate* data;
    int size;
} CoordinateTransformer;

typedef struct {
    Coordinate* data;
    int size;
} DataProcessor;

typedef struct {
    Coordinate* data;
    int size;
} SequenceAnalyzer;

void CoordinateTransformer_init(CoordinateTransformer* self, Coordinate* data, int size) {
    self->data = data;
    self->size = size;
}

Coordinate rotate(Coordinate item) {
    double angle = 45;
    double radian = angle * 3.14159 / 180;
    double cos_angle = cos(radian);
    double sin_angle = sin(radian);
    Coordinate result;
    result.x = item.x * cos_angle - item.y * sin_angle;
    result.y = item.x * sin_angle + item.y * cos_angle;
    result.z = item.z;
    return result;
}

Coordinate* CoordinateTransformer_transform(CoordinateTransformer* self, Coordinate* results) {
    for (int i = 0; i < self->size; i++) {
        results[i] = rotate(self->data[i]);
    }
    return results;
}

void DataProcessor_init(DataProcessor* self, Coordinate* data, int size) {
    self->data = data;
    self->size = size;
}

Coordinate* DataProcessor_process(DataProcessor* self, Coordinate* results) {
    CoordinateTransformer transformer;
    CoordinateTransformer_init(&transformer, self->data, self->size);
    return CoordinateTransformer_transform(&transformer, results);
}

void SequenceAnalyzer_init(SequenceAnalyzer* self, Coordinate* data, int size) {
    self->data = data;
    self->size = size;
}

Coordinate* SequenceAnalyzer_analyze(SequenceAnalyzer* self, Coordinate* results) {
    DataProcessor processor;
    DataProcessor_init(&processor, self->data, self->size);
    return DataProcessor_process(&processor, results);
}

int main() {
    Coordinate sequence[] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    Coordinate results[size];
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, sequence, size);
    Coordinate* result = SequenceAnalyzer_analyze(&analyzer, results);
    for (int i = 0; i < size; i++) {
        printf("(%f, %f, %f)\n", result[i].x, result[i].y, result[i].z);
    }
    return 0;
}