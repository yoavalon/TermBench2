#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    double x;
    double y;
    double z;
} Vector;

Vector Vector_init(double x, double y, double z) {
    Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector Vector_add(Vector self, Vector other) {
    return Vector_init(self.x + other.x, self.y + other.y, self.z + other.z);
}

Vector Vector_scale(Vector self, double scalar) {
    return Vector_init(self.x * scalar, self.y * scalar, self.z * scalar);
}

void Vector_repr(Vector self) {
    printf("Vector(%.1f, %.1f, %.1f)\n", self.x, self.y, self.z);
}

typedef struct Transformation {
    double rotation_matrix[3][3];
    Vector translation_vector;
} Transformation;

Transformation Transformation_init(double rotation_matrix[3][3], Vector translation_vector) {
    Transformation t;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t.rotation_matrix[i][j] = rotation_matrix[i][j];
        }
    }
    t.translation_vector = translation_vector;
    return t;
}

Vector Transformation_apply(Transformation self, Vector vector) {
    Vector rotated = Vector_init(
        self.rotation_matrix[0][0] * vector.x + self.rotation_matrix[0][1] * vector.y + self.rotation_matrix[0][2] * vector.z,
        self.rotation_matrix[1][0] * vector.x + self.rotation_matrix[1][1] * vector.y + self.rotation_matrix[1][2] * vector.z,
        self.rotation_matrix[2][0] * vector.x + self.rotation_matrix[2][1] * vector.y + self.rotation_matrix[2][2] * vector.z
    );
    Vector translated = Vector_add(rotated, self.translation_vector);
    return translated;
}

typedef struct Processor {
    Transformation* transformations;
    int transformation_count;
} Processor;

Processor Processor_init() {
    Processor p;
    p.transformations = NULL;
    p.transformation_count = 0;
    return p;
}

void Processor_add_transformation(Processor* self, Transformation transformation) {
    self->transformation_count++;
    self->transformations = realloc(self->transformations, self->transformation_count * sizeof(Transformation));
    self->transformations[self->transformation_count - 1] = transformation;
}

Vector Processor_process(Processor self, Vector vector) {
    for (int i = 0; i < self.transformation_count; i++) {
        vector = Transformation_apply(self.transformations[i], vector);
    }
    return vector;
}

void main() {
    double rotation_matrix[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    Vector translation_vector = Vector_init(1.0, 2.0, 3.0);
    Transformation transformation = Transformation_init(rotation_matrix, translation_vector);
    Processor processor = Processor_init();
    Processor_add_transformation(&processor, transformation);
    Vector initial_vector = Vector_init(0.0, 0.0, 0.0);
    Vector final_vector = Processor_process(processor, initial_vector);
    Vector_repr(final_vector);
}