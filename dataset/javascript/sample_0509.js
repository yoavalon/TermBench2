class SystemState {
    constructor(temp, pressure, volume) {
        this.temp = temp;
        this.pressure = pressure;
        this.volume = volume;
    }

    update(temp_change, pressure_change, volume_change) {
        this.temp += temp_change;
        this.pressure += pressure_change;
        this.volume += volume_change;
    }
}

class Simulation {
    constructor(initial_state) {
        this.state = initial_state;
        this.conditions = [];
    }

    add_condition(condition) {
        this.conditions.push(condition);
    }

    run() {
        while (true) {
            for (let condition of this.conditions) {
                condition(this.state);
            }
        }
    }
}

class BoundaryCondition {
    constructor(threshold, effect) {
        this.threshold = threshold;
        this.effect = effect;
    }

    __call__(state) {
        if (state.temp > this.threshold) {
            this.effect(state);
        }
    }
}

function apply_effect(state) {
    state.update(-10, 5, -2);
}

function main() {
    let initial_state = new SystemState(300, 101325, 0.5);
    let simulation = new Simulation(initial_state);
    let condition = new BoundaryCondition(350, apply_effect);
    simulation.add_condition(condition);
    simulation.run();
}

main();