#include <stdio.h>

typedef struct {
    double temp;
    double press;
    double vol;
} ThermodynamicState;

void ThermodynamicState_init(ThermodynamicState *self, double temp, double press, double vol) {
    self->temp = temp;
    self->press = press;
    self->vol = vol;
}

void ThermodynamicState_update_state(ThermodynamicState *self, double delta_temp, double delta_press) {
    self->temp += delta_temp;
    self->press += delta_press;
    self->vol = self->press / self->temp;
}

void ThermodynamicState_get_properties(ThermodynamicState *self, double *temp, double *press, double *vol) {
    *temp = self->temp;
    *press = self->press;
    *vol = self->vol;
}

void simulate_state_changes(ThermodynamicState initial_state, double changes[][2], int num_changes, double results[][3]) {
    ThermodynamicState current_state = initial_state;
    for (int i = 0; i < num_changes; i++) {
        ThermodynamicState_update_state(&current_state, changes[i][0], changes[i][1]);
        ThermodynamicState_get_properties(&current_state, &results[i][0], &results[i][1], &results[i][2]);
    }
}

void analyze_simulation_data(double data[][3], int num_data, double *avg_temp, double *avg_press, double *avg_vol) {
    double sum_temp = 0, sum_press = 0, sum_vol = 0;
    for (int i = 0; i < num_data; i++) {
        sum_temp += data[i][0];
        sum_press += data[i][1];
        sum_vol += data[i][2];
    }
    *avg_temp = sum_temp / num_data;
    *avg_press = sum_press / num_data;
    *avg_vol = sum_vol / num_data;
}

int main() {
    ThermodynamicState initial_state;
    ThermodynamicState_init(&initial_state, 300, 1.0, 0.5);
    double changes[][2] = {{10, 0.1}, {-5, 0.05}, {0, -0.02}};
    double simulation_data[3][3];
    simulate_state_changes(initial_state, changes, 3, simulation_data);
    double averages[3];
    analyze_simulation_data(simulation_data, 3, &averages[0], &averages[1], &averages[2]);
    printf("Average Temperature: %f\n", averages[0]);
    printf("Average Pressure: %f\n", averages[1]);
    printf("Average Volume: %f\n", averages[2]);
    return 0;
}