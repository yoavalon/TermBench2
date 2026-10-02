#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Vector origin;
} CoordinateSystem;

CoordinateSystem* CoordinateSystem_init() {
    CoordinateSystem* cs = (CoordinateSystem*)malloc(sizeof(CoordinateSystem));
    cs->origin = (Vector){0.0, 0.0, 0.0};
    return cs;
}

Vector CoordinateSystem_transform(CoordinateSystem* cs, Vector vector, double scale) {
    return (Vector){vector.x * scale, vector.y * scale, vector.z * scale};
}

Vector CoordinateSystem_rotate(CoordinateSystem* cs, Vector vector, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    return (Vector){vector.x * cos_a - vector.y * sin_a, vector.x * sin_a + vector.y * cos_a, vector.z};
}

typedef struct {
    CoordinateSystem* coordinate_system;
} TransformationManager;

TransformationManager* TransformationManager_init() {
    TransformationManager* tm = (TransformationManager*)malloc(sizeof(TransformationManager));
    tm->coordinate_system = CoordinateSystem_init();
    return tm;
}

Vector TransformationManager_apply_transformations(TransformationManager* tm, Vector vector, double scale, double angle) {
    Vector scaled_vector = CoordinateSystem_transform(tm->coordinate_system, vector, scale);
    Vector rotated_vector = CoordinateSystem_rotate(tm->coordinate_system, scaled_vector, angle);
    return rotated_vector;
}

typedef struct {
    TransformationManager* manager;
    Vector vector;
    double scale;
    double angle;
} SimulationEngine;

SimulationEngine* SimulationEngine_init() {
    SimulationEngine* se = (SimulationEngine*)malloc(sizeof(SimulationEngine));
    se->manager = TransformationManager_init();
    se->vector = (Vector){1.0, 1.0, 1.0};
    se->scale = 2.0;
    se->angle = 0.1;
    return se;
}

void SimulationEngine_run(SimulationEngine* se) {
    while (1) {
        Vector result = TransformationManager_apply_transformations(se->manager, se->vector, se->scale, se->angle);
        se->vector = result;
        se->angle += 0.01;
    }
}

int main() {
    SimulationEngine* engine = SimulationEngine_init();
    SimulationEngine_run(engine);
    return 0;
}