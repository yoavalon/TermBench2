#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int state;
} StateMachine;

void StateMachine_init(StateMachine *self) {
    self->state = 0;
}

void StateMachine_transition(StateMachine *self, int input_value) {
    if (self->state == 0) {
        if (input_value == 0) {
            self->state = 1;
        } else if (input_value == 1) {
            self->state = 2;
        }
    } else if (self->state == 1) {
        if (input_value == 0) {
            self->state = 0;
        } else if (input_value == 1) {
            self->state = 3;
        }
    } else if (self->state == 2) {
        if (input_value == 0) {
            self->state = 3;
        } else if (input_value == 1) {
            self->state = 1;
        }
    } else if (self->state == 3) {
        if (input_value == 0) {
            self->state = 2;
        } else if (input_value == 1) {
            self->state = 0;
        }
    }
}

int StateMachine_get_state(StateMachine *self) {
    return self->state;
}

typedef struct {
    int *sequence;
    int current_value;
    int size;
    int capacity;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self) {
    self->sequence = NULL;
    self->current_value = 0;
    self->size = 0;
    self->capacity = 0;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    if (self->size >= self->capacity) {
        self->capacity = (self->capacity == 0) ? 1 : self->capacity * 2;
        self->sequence = (int *)realloc(self->sequence, self->capacity * sizeof(int));
    }
    self->sequence[self->size++] = self->current_value;
    self->current_value = (self->current_value + 1) % 2;
    return self->sequence[self->size - 1];
}

typedef struct {
    StateMachine *state_machine;
    SequenceGenerator *sequence_generator;
    int index;
} StateGenerator;

void StateGenerator_init(StateGenerator *self, StateMachine *state_machine, SequenceGenerator *sequence_generator) {
    self->state_machine = state_machine;
    self->sequence_generator = sequence_generator;
    self->index = 0;
}

int StateGenerator_next(StateGenerator *self) {
    int value = SequenceGenerator_next(self->sequence_generator);
    StateMachine_transition(self->state_machine, value);
    return StateMachine_get_state(self->state_machine);
}

int main() {
    StateMachine state_machine;
    SequenceGenerator sequence_generator;
    StateGenerator state_generator;

    StateMachine_init(&state_machine);
    SequenceGenerator_init(&sequence_generator);
    StateGenerator_init(&state_generator, &state_machine, &sequence_generator);

    while (true) {
        int state = StateGenerator_next(&state_generator);
        printf("%d\n", state);
    }

    return 0;
}