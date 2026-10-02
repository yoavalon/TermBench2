class ThermodynamicState {
    constructor(temperature, pressure) {
        this.temperature = temperature;
        this.pressure = pressure;
    }

    update_state(delta_temp, delta_press) {
        this.temperature += delta_temp;
        this.pressure += delta_press;
    }
}

class BoundaryConditions {
    constructor(max_temp, min_temp, max_press, min_press) {
        this.max_temp = max_temp;
        this.min_temp = min_temp;
        this.max_press = max_press;
        this.min_press = min_press;
    }

    check_boundaries(state) {
        if (state.temperature > this.max_temp) {
            state.temperature = this.max_temp;
        } else if (state.temperature < this.min_temp) {
            state.temperature = this.min_temp;
        }
        if (state.pressure > this.max_press) {
            state.pressure = this.max_press;
        } else if (state.pressure < this.min_press) {
            state.pressure = this.min_press;
        }
    }
}

function simulate(state, conditions) {
    while (true) {
        let delta_temp = 1.5;
        let delta_press = -0.5;
        state.update_state(delta_temp, delta_press);
        conditions.check_boundaries(state);
    }
}

function main() {
    let initial_temp = 300;
    let initial_press = 1.0;
    let max_temp = 500;
    let min_temp = 200;
    let max_press = 2.0;
    let min_press = 0.5;
    let state = new ThermodynamicState(initial_temp, initial_press);
    let conditions = new BoundaryConditions(max_temp, min_temp, max_press, min_press);
    simulate(state, conditions);
}

main();