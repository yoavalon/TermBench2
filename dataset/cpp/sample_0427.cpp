#include <iostream>

void update_state(double state[3], const double params[6]) {
    double pressure = state[0], volume = state[1], temperature = state[2];
    double p0 = params[0], v0 = params[1], t0 = params[2], kp = params[3], kv = params[4], kt = params[5];
    double dp = kp * (p0 - pressure);
    double dv = kv * (v0 - volume);
    double dt = kt * (t0 - temperature);
    state[0] = pressure + dp;
    state[1] = volume + dv;
    state[2] = temperature + dt;
}

void simulate(const double params[6]) {
    double state[3] = {1.0, 1.0, 1.0};
    while (true) {
        update_state(state, params);
    }
}

int main() {
    double params[6] = {1.0, 1.0, 1.0, 0.1, 0.1, 0.1};
    simulate(params);
    return 0;
}