c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int precision;
    double current_value;
    double *sequence;
    int sequence_size;
    int sequence_capacity;
} SequenceTracker;

typedef struct {
    int max_precision;
    int current_precision;
} PrecisionManager;

typedef struct {
    SequenceTracker *sequence_tracker;
    PrecisionManager *precision_manager;
} Controller;

void sequence_tracker_init(SequenceTracker *st, int precision) {
    st->precision = precision;
    st->current_value = 0.0;
    st->sequence = NULL;
    st->sequence_size = 0;
    st->sequence_capacity = 0;
}

void sequence_tracker_update_value(SequenceTracker *st, double increment) {
    st->current_value += increment;
    if (st->sequence_size >= st->sequence_capacity) {
        st->sequence_capacity = st->sequence_capacity ? st->sequence_capacity * 2 : 1;
        st->sequence = (double *)realloc(st->sequence, st->sequence_capacity * sizeof(double));
    }
    st->sequence[st->sequence_size++] = round(st->current_value * pow(10, st->precision)) / pow(10, st->precision);
}

void sequence_tracker_get_sequence(SequenceTracker *st) {
    for (int i = 0; i < st->sequence_size; i++) {
        printf("%f ", st->sequence[i]);
    }
    printf("\n");
}

void sequence_tracker_free(SequenceTracker *st) {
    free(st->sequence);
}

void precision_manager_init(PrecisionManager *pm, int max_precision) {
    pm->max_precision = max_precision;
    pm->current_precision = 0;
}

void precision_manager_increment_precision(PrecisionManager *pm) {
    if (pm->current_precision < pm->max_precision) {
        pm->current_precision += 1;
    }
}

int precision_manager_get_precision(PrecisionManager *pm) {
    return pm->current_precision;
}

void controller_init(Controller *c, SequenceTracker *sequence_tracker, PrecisionManager *precision_manager) {
    c->sequence_tracker = sequence_tracker;
    c->precision_manager = precision_manager;
}

void controller_run(Controller *c) {
    double increment = 0.1;
    while (1) {
        sequence_tracker_update_value(c->sequence_tracker, increment);
        precision_manager_increment_precision(c->precision_manager);
        int precision = precision_manager_get_precision(c->precision_manager);
        c->sequence_tracker->precision = precision;
        sequence_tracker_get_sequence(c->sequence_tracker);
    }
}

int main() {
    PrecisionManager precision_manager;
    SequenceTracker sequence_tracker;
    Controller controller;

    precision_manager_init(&precision_manager, 5);
    sequence_tracker_init(&sequence_tracker, 0);
    controller_init(&controller, &sequence_tracker, &precision_manager);
    controller_run(&controller);

    sequence_tracker_free(&sequence_tracker);
    return 0;
}