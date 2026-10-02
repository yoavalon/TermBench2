#include <stdio.h>
#include <math.h>

typedef struct {
    double matrix[3][3];
} Transformer;

void Transformer_init(Transformer *self) {
    self->matrix[0][0] = 1; self->matrix[0][1] = 0; self->matrix[0][2] = 0;
    self->matrix[1][0] = 0; self->matrix[1][1] = 1; self->matrix[1][2] = 0;
    self->matrix[2][0] = 0; self->matrix[2][1] = 0; self->matrix[2][2] = 1;
}

void Transformer_apply_transformation(Transformer *self, double point[3], double result[3]) {
    result[0] = self->matrix[0][0] * point[0] + self->matrix[0][1] * point[1] + self->matrix[0][2] * point[2];
    result[1] = self->matrix[1][0] * point[0] + self->matrix[1][1] * point[1] + self->matrix[1][2] * point[2];
    result[2] = self->matrix[2][0] * point[0] + self->matrix[2][1] * point[1] + self->matrix[2][2] * point[2];
}

void Transformer_rotate_x(Transformer *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    self->matrix[0][0] = 1; self->matrix[0][1] = 0; self->matrix[0][2] = 0;
    self->matrix[1][0] = 0; self->matrix[1][1] = cos_a; self->matrix[1][2] = -sin_a;
    self->matrix[2][0] = 0; self->matrix[2][1] = sin_a; self->matrix[2][2] = cos_a;
}

void Transformer_rotate_y(Transformer *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    self->matrix[0][0] = cos_a; self->matrix[0][1] = 0; self->matrix[0][2] = sin_a;
    self->matrix[1][0] = 0; self->matrix[1][1] = 1; self->matrix[1][2] = 0;
    self->matrix[2][0] = -sin_a; self->matrix[2][1] = 0; self->matrix[2][2] = cos_a;
}

void Transformer_rotate_z(Transformer *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    self->matrix[0][0] = cos_a; self->matrix[0][1] = -sin_a; self->matrix[0][2] = 0;
    self->matrix[1][0] = sin_a; self->matrix[1][1] = cos_a; self->matrix[1][2] = 0;
    self->matrix[2][0] = 0; self->matrix[2][1] = 0; self->matrix[2][2] = 1;
}

typedef struct {
    Transformer *transformer;
    double current_point[3];
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, Transformer *transformer) {
    self->transformer = transformer;
    self->current_point[0] = 1; self->current_point[1] = 0; self->current_point[2] = 0;
}

void SequenceGenerator_generate_sequence(SequenceGenerator *self) {
    while (1) {
        printf("(%.2f, %.2f, %.2f)\n", self->current_point[0], self->current_point[1], self->current_point[2]);
        double result[3];
        Transformer_apply_transformation(self->transformer, self->current_point, result);
        for (int i = 0; i < 3; i++) {
            self->current_point[i] = result[i];
        }
    }
}

int main() {
    Transformer transformer;
    Transformer_init(&transformer);
    Transformer_rotate_x(&transformer, 0.1);
    Transformer_rotate_y(&transformer, 0.1);
    Transformer_rotate_z(&transformer, 0.1);
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, &transformer);
    SequenceGenerator_generate_sequence(&generator);
    return 0;
}