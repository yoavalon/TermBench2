#include <stdio.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
} CoordinateTransformer;

void CoordinateTransformer_init(CoordinateTransformer *self, double x, double y, double z) {
    self->a = x;
    self->b = y;
    self->c = z;
}

void CoordinateTransformer_rotate(CoordinateTransformer *self, double angle) {
    double rad = angle * M_PI / 180.0;
    double x = self->a * cos(rad) - self->b * sin(rad);
    double y = self->a * sin(rad) + self->b * cos(rad);
    self->a = x;
    self->b = y;
}

void CoordinateTransformer_translate(CoordinateTransformer *self, double x_offset, double y_offset, double z_offset) {
    self->a += x_offset;
    self->b += y_offset;
    self->c += z_offset;
}

void CoordinateTransformer_scale(CoordinateTransformer *self, double factor) {
    self->a *= factor;
    self->b *= factor;
    self->c *= factor;
}

void process_coordinates(CoordinateTransformer *transformer, const char **operations, int num_operations) {
    for (int i = 0; i < num_operations; i++) {
        if (strcmp(operations[i], "rotate") == 0) {
            double angle = atof(operations[i + 1]);
            CoordinateTransformer_rotate(transformer, angle);
            i++;
        } else if (strcmp(operations[i], "translate") == 0) {
            double x_offset = atof(operations[i + 1]);
            double y_offset = atof(operations[i + 2]);
            double z_offset = atof(operations[i + 3]);
            CoordinateTransformer_translate(transformer, x_offset, y_offset, z_offset);
            i += 3;
        } else if (strcmp(operations[i], "scale") == 0) {
            double factor = atof(operations[i + 1]);
            CoordinateTransformer_scale(transformer, factor);
            i++;
        }
    }
}

int main() {
    CoordinateTransformer transformer;
    CoordinateTransformer_init(&transformer, 1, 2, 3);
    const char *operations[] = {"rotate", "45", "translate", "1", "1", "1", "scale", "2", "rotate", "90", "translate", "-1", "-1", "-1", "scale", "0.5"};
    int num_operations = sizeof(operations) / sizeof(operations[0]);
    while (1) {
        process_coordinates(&transformer, operations, num_operations);
    }
    return 0;
}