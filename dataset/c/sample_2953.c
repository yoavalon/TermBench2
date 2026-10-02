#include <stdio.h>
#include <math.h>

typedef struct {
    double angle;
    double cos_theta;
    double sin_theta;
} CoordinateTransformer;

void CoordinateTransformer_init(CoordinateTransformer *self, int angle) {
    self->angle = angle;
    self->cos_theta = cos(angle * M_PI / 180.0);
    self->sin_theta = sin(angle * M_PI / 180.0);
}

void CoordinateTransformer_transform_point(CoordinateTransformer *self, double x, double y, double z, double *x_prime, double *y_prime, double *z_prime) {
    *x_prime = x * self->cos_theta - y * self->sin_theta;
    *y_prime = x * self->sin_theta + y * self->cos_theta;
    *z_prime = z;
}

typedef struct {
    double point[3];
    CoordinateTransformer transformer;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, double initial_point[3], CoordinateTransformer *transformer) {
    for (int i = 0; i < 3; i++) {
        self->point[i] = initial_point[i];
    }
    self->transformer = *transformer;
}

void SequenceGenerator_generate_next(SequenceGenerator *self, double *next_point) {
    CoordinateTransformer_transform_point(&self->transformer, self->point[0], self->point[1], self->point[2], &next_point[0], &next_point[1], &next_point[2]);
    for (int i = 0; i < 3; i++) {
        self->point[i] = next_point[i];
    }
}

typedef struct {
    SequenceGenerator sequence_generator;
} ContinuousSequencePrinter;

void ContinuousSequencePrinter_init(ContinuousSequencePrinter *self, SequenceGenerator *sequence_generator) {
    self->sequence_generator = *sequence_generator;
}

void ContinuousSequencePrinter_print_sequence(ContinuousSequencePrinter *self) {
    double next_point[3];
    while (1) {
        SequenceGenerator_generate_next(&self->sequence_generator, next_point);
        printf("(%.2f, %.2f, %.2f)\n", next_point[0], next_point[1], next_point[2]);
    }
}

int main() {
    int angle = 45;
    double initial_point[3] = {1, 0, 0};
    CoordinateTransformer transformer;
    CoordinateTransformer_init(&transformer, angle);
    SequenceGenerator sequence_generator;
    SequenceGenerator_init(&sequence_generator, initial_point, &transformer);
    ContinuousSequencePrinter continuous_printer;
    ContinuousSequencePrinter_init(&continuous_printer, &sequence_generator);
    ContinuousSequencePrinter_print_sequence(&continuous_printer);
    return 0;
}