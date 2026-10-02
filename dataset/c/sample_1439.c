#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
} StateSimulator;

typedef struct {
    int (*condition)(int);
    int (*action)(int);
} RuleApplier;

typedef struct {
    int* conditions;
    RuleApplier rule;
} TransitionRule;

int condition_a(int state) {
    return state < 100;
}

int action_a(int state) {
    return state + 10;
}

int condition_b(int state) {
    return state >= 100;
}

int action_b(int state) {
    return state - 5;
}

void StateSimulator_init(StateSimulator* self, int initial_state, TransitionRule* rules, int num_rules) {
    self->state = initial_state;
    self->rules = rules;
    self->num_rules = num_rules;
}

int StateSimulator_apply_rules(StateSimulator* self) {
    int new_state = self->state;
    for (int i = 0; i < self->num_rules; i++) {
        for (int j = 0; self->rules[i].conditions[j] != '\0'; j++) {
            if (self->state == self->rules[i].conditions[j]) {
                new_state = self->rules[i].rule.action(self->state);
                break;
            }
        }
    }
    return new_state;
}

void StateSimulator_simulate(StateSimulator* self, int steps) {
    for (int i = 0; i < steps; i++) {
        self->state = StateSimulator_apply_rules(self);
    }
}

int RuleApplier_call(RuleApplier* self, int state) {
    if (self->condition(state)) {
        return self->action(state);
    }
    return state;
}

int main() {
    int initial_state = 50;
    TransitionRule rules[] = {
        {{'a'}, {condition_a, action_a}},
        {{'b'}, {condition_b, action_b}}
    };
    int num_rules = sizeof(rules) / sizeof(rules[0]);
    StateSimulator simulator;
    StateSimulator_init(&simulator, initial_state, rules, num_rules);
    StateSimulator_simulate(&simulator, 20);
    printf("%d\n", simulator.state);
    return 0;
}