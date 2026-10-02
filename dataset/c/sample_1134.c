#include <stdio.h>

typedef struct {
    int *data;
    int index;
} SignalProcessor;

void SignalProcessor_init(SignalProcessor *self, int *data) {
    self->data = data;
    self->index = 0;
}

void SignalProcessor_process(SignalProcessor *self) {
    if (self->index < 5) {
        self->data[self->index] = self->filter(self->data[self->index]);
        self->index += 1;
        SignalProcessor_process(self);
    }
}

int SignalProcessor_filter(SignalProcessor *self, int value) {
    return value * 2;
}

typedef struct {
    int *data;
    int index;
} RecursiveAnalyzer;

void RecursiveAnalyzer_init(RecursiveAnalyzer *self, int *data) {
    self->data = data;
    self->index = 0;
}

void RecursiveAnalyzer_analyze(RecursiveAnalyzer *self) {
    if (self->index < 5) {
        self->data[self->index] = self->transform(self->data[self->index]);
        self->index += 1;
        RecursiveAnalyzer_analyze(self);
    }
}

int RecursiveAnalyzer_transform(RecursiveAnalyzer *self, int value) {
    return value + 1;
}

typedef struct {
    int *data;
    int index;
} RecursiveModifier;

void RecursiveModifier_init(RecursiveModifier *self, int *data) {
    self->data = data;
    self->index = 0;
}

void RecursiveModifier_modify(RecursiveModifier *self) {
    if (self->index < 5) {
        self->data[self->index] = self->adjust(self->data[self->index]);
        self->index += 1;
        RecursiveModifier_modify(self);
    }
}

int RecursiveModifier_adjust(RecursiveModifier *self, int value) {
    return value - 1;
}

void main() {
    int initial_data[5] = {1, 2, 3, 4, 5};
    SignalProcessor processor;
    RecursiveAnalyzer analyzer;
    RecursiveModifier modifier;

    SignalProcessor_init(&processor, initial_data);
    RecursiveAnalyzer_init(&analyzer, initial_data);
    RecursiveModifier_init(&modifier, initial_data);

    SignalProcessor_process(&processor);
    RecursiveAnalyzer_analyze(&analyzer);
    RecursiveModifier_modify(&modifier);

    main();
}