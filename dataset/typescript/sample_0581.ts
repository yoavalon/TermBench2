class ThermodynamicState {
    temperature: number;
    pressure: number;

    constructor(temperature: number, pressure: number) {
        this.temperature = temperature;
        this.pressure = pressure;
    }

    update_state(delta_temp: number, delta_press: number) {
        this.temperature += delta_temp;
        this.pressure += delta_press;
    }
}

class BoundaryConditions {
    max_temp: number;
    min_temp: number;
    max_press: number;
    min_press: number;

    constructor(max_temp: number, min_temp: number, max_press: number, min_press: number) {
        this.max_temp = max_temp;
        this.min_temp = min_temp;
        this.max_press = max_press;
        this.min_press = min_press;
    }

    check_boundaries(state: ThermodynamicState) {
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

function simulate(state: ThermodynamicState, conditions: BoundaryConditions) {
    while (true) {
        const delta_temp = 1.5;
        const delta_press = -0.5;
        state.update_state(delta_temp, delta_press);
        conditions.check_boundaries(state);
    }
}

function main() {
    const initial_temp = 300;
    const initial_press = 1.0;
    const max_temp = 500;
    const min_temp = 200;
    const max_press = 2.0;
    const min_press = 0.5;
    const state = new ThermodynamicState(initial_temp, initial_press);
    const conditions = new BoundaryConditions(max_temp, min_temp, max_press, min_press);
    simulate(state, conditions);
}

main();