#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
    int* sequence;
    int sequence_size;
} SequenceSimulator;

typedef struct {
    int* sequence;
    int sequence_size;
} StateAnalyzer;

typedef struct {
    SequenceSimulator* simulator;
    StateAnalyzer* analyzer;
} MainController;

void SequenceSimulator_init(SequenceSimulator* self) {
    self->state = 0;
    self->sequence = NULL;
    self->sequence_size = 0;
}

void SequenceSimulator_update_state(SequenceSimulator* self) {
    self->state = (self->state * 3 + 1) % 1000;
}

void SequenceSimulator_generate_sequence(SequenceSimulator* self) {
    while (1) {
        self->sequence = realloc(self->sequence, (self->sequence_size + 1) * sizeof(int));
        self->sequence[self->sequence_size++] = self->state;
        SequenceSimulator_update_state(self);
    }
}

void StateAnalyzer_init(StateAnalyzer* self, int* sequence, int sequence_size) {
    self->sequence = sequence;
    self->sequence_size = sequence_size;
}

int StateAnalyzer_analyze(StateAnalyzer* self) {
    while (1) {
        int unique_values[1000] = {0};
        int unique_count = 0;
        for (int i = 0; i < self->sequence_size; i++) {
            if (!unique_values[self->sequence[i]]) {
                unique_values[self->sequence[i]] = 1;
                unique_count++;
            }
        }
        if (unique_count == 1) {
            for (int i = 0; i < 1000; i++) {
                if (unique_values[i]) {
                    return i;
                }
            }
        } else {
            self->sequence++;
            self->sequence_size--;
        }
    }
}

void MainController_init(MainController* self) {
    self->simulator = malloc(sizeof(SequenceSimulator));
    SequenceSimulator_init(self->simulator);
    self->analyzer = malloc(sizeof(StateAnalyzer));
    StateAnalyzer_init(self->analyzer, self->simulator->sequence, self->simulator->sequence_size);
}

void MainController_run(MainController* self) {
    SequenceSimulator_generate_sequence(self->simulator);
    StateAnalyzer_analyze(self->analyzer);
}

int main() {
    MainController controller;
    MainController_init(&controller);
    MainController_run(&controller);
    return 0;
}