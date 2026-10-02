#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct Particle {
    double position[2];
    double velocity[2];
    double best[2];
} Particle;

typedef struct Swarm {
    Particle* particles;
    Particle best;
    int size;
} Swarm;

double random_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

Particle create_particle() {
    Particle p;
    p.position[0] = random_double(-1, 1);
    p.position[1] = random_double(-1, 1);
    p.velocity[0] = random_double(-0.1, 0.1);
    p.velocity[1] = random_double(-0.1, 0.1);
    p.best[0] = p.position[0];
    p.best[1] = p.position[1];
    return p;
}

double evaluate(Particle* p) {
    return -(p->position[0] * p->position[0] + p->position[1] * p->position[1]);
}

void update_velocity(Particle* p, Particle* global_best) {
    double inertia = 0.7;
    double cognitive = 1.5;
    double social = 1.5;
    for (int i = 0; i < 2; i++) {
        double r1 = (double)rand() / RAND_MAX;
        double r2 = (double)rand() / RAND_MAX;
        double cognitive_component = cognitive * r1 * (p->best[i] - p->position[i]);
        double social_component = social * r2 * (global_best->position[i] - p->position[i]);
        p->velocity[i] = inertia * p->velocity[i] + cognitive_component + social_component;
    }
}

void move(Particle* p) {
    for (int i = 0; i < 2; i++) {
        p->position[i] += p->velocity[i];
        p->position[i] = fmax(-1, fmin(1, p->position[i]));
    }
    double current_eval = evaluate(p);
    if (current_eval < evaluate(&(p->best))) {
        p->best[0] = p->position[0];
        p->best[1] = p->position[1];
    }
}

Swarm create_swarm(int size) {
    Swarm s;
    s.size = size;
    s.particles = (Particle*)malloc(size * sizeof(Particle));
    for (int i = 0; i < size; i++) {
        s.particles[i] = create_particle();
    }
    s.best = s.particles[0];
    for (int i = 1; i < size; i++) {
        if (evaluate(&(s.particles[i])) < evaluate(&(s.best))) {
            s.best = s.particles[i];
        }
    }
    return s;
}

void update_swarm(Swarm* s) {
    for (int i = 0; i < s->size; i++) {
        update_velocity(&(s->particles[i]), &(s->best));
        move(&(s->particles[i]));
    }
    for (int i = 0; i < s->size; i++) {
        if (evaluate(&(s->particles[i])) < evaluate(&(s->best))) {
            s->best = s->particles[i];
        }
    }
}

void run() {
    int swarm_size = 30;
    Swarm swarm = create_swarm(swarm_size);
    while (1) {
        update_swarm(&swarm);
    }
}

int main() {
    srand(time(NULL));
    run();
    return 0;
}