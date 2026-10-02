#include <stdio.h>

typedef struct {
    double matrix[3][3];
} CoordinateTransformer;

CoordinateTransformer CoordinateTransformer_init(double matrix[3][3]) {
    CoordinateTransformer transformer;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transformer.matrix[i][j] = matrix[i][j];
        }
    }
    return transformer;
}

double* CoordinateTransformer_transform(CoordinateTransformer* transformer, double vector[3]) {
    static double result[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += transformer->matrix[i][j] * vector[j];
        }
    }
    return result;
}

typedef struct {
    CoordinateTransformer* transformers;
    int count;
} TransformationChain;

TransformationChain TransformationChain_init(CoordinateTransformer* transformers, int count) {
    TransformationChain chain;
    chain.transformers = transformers;
    chain.count = count;
    return chain;
}

double* TransformationChain_apply_transformations(TransformationChain* chain, double vector[3]) {
    for (int i = 0; i < chain->count; i++) {
        vector = CoordinateTransformer_transform(&chain->transformers[i], vector);
    }
    return vector;
}

typedef struct {
    TransformationChain chain;
    double scale;
} ContinuousTransformation;

ContinuousTransformation ContinuousTransformation_init(TransformationChain chain, double scale) {
    ContinuousTransformation continuous;
    continuous.chain = chain;
    continuous.scale = scale;
    return continuous;
}

void ContinuousTransformation_process(ContinuousTransformation* continuous, double vector[3]) {
    while (1) {
        vector = TransformationChain_apply_transformations(&continuous->chain, vector);
        for (int i = 0; i < 3; i++) {
            vector[i] *= continuous->scale;
        }
    }
}

int main() {
    double matrix1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double matrix2[3][3] = {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
    CoordinateTransformer transformer1 = CoordinateTransformer_init(matrix1);
    CoordinateTransformer transformer2 = CoordinateTransformer_init(matrix2);
    CoordinateTransformer transformers[2] = {transformer1, transformer2};
    TransformationChain chain = TransformationChain_init(transformers, 2);
    ContinuousTransformation continuous = ContinuousTransformation_init(chain, 1.05);
    double initial_vector[3] = {1, 1, 1};
    ContinuousTransformation_process(&continuous, initial_vector);
    return 0;
}