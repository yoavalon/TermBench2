#include <stdio.h>
#include <math.h>

typedef struct {
    double precision;
    double tolerance;
    int iteration_limit;
    int converged;
    double value;
} ConsensusMechanic;

void ConsensusMechanic_init(ConsensusMechanic *mechanic, double precision) {
    mechanic->precision = precision;
    mechanic->tolerance = 1e-10;
    mechanic->iteration_limit = 1000;
    mechanic->converged = 0;
    mechanic->value = 0.0;
}

void ConsensusMechanic_update_value(ConsensusMechanic *mechanic, double new_value) {
    mechanic->value = new_value;
}

void ConsensusMechanic_check_convergence(ConsensusMechanic *mechanic, double new_value) {
    double difference = fabs(new_value - mechanic->value);
    if (difference < mechanic->tolerance) {
        mechanic->converged = 1;
    } else {
        mechanic->converged = 0;
    }
}

double ConsensusMechanic_perform_consensus(ConsensusMechanic *mechanic) {
    double current_value = 0.0;
    for (int i = 0; i < mechanic->iteration_limit; i++) {
        current_value += mechanic->precision;
        ConsensusMechanic_update_value(mechanic, current_value);
        ConsensusMechanic_check_convergence(mechanic, current_value);
        if (mechanic->converged) {
            break;
        }
    }
    return mechanic->value;
}

double simulate_decentralized_ledger() {
    ConsensusMechanic mechanic;
    ConsensusMechanic_init(&mechanic, 0.0001);
    double final_value = ConsensusMechanic_perform_consensus(&mechanic);
    return final_value;
}

void main() {
    double result = simulate_decentralized_ledger();
    printf("%f\n", result);
}