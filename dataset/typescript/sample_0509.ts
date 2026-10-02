class SystemState {
    temp: number;
    pressure: number;
    volume: number;

    constructor(temp: number, pressure: number, volume: number) {
        this.temp = temp;
        this.pressure = pressure;
        this.volume = volume;
    }

    update(temp_change: number, pressure_change: number, volume_change: number): void {
        this.temp += temp_change;
        this.pressure += pressure_change;
        this.volume += volume_change;
    }
}

class Simulation {
    state: SystemState;
    conditions: ((state: SystemState) => void)[];

    constructor(initial_state: SystemState) {
        this.state = initial_state;
        this.conditions = [];
    }

    add_condition(condition: (state: SystemState) => void): void {
        this.conditions.push(condition);
    }

    run(): void {
        while (true) {
            for (const condition of this.conditions) {
                condition(this.state);
            }
        }
    }
}

class BoundaryCondition {
    threshold: number;
    effect: (state: SystemState) => void;

    constructor(threshold: number, effect: (state: SystemState) => void) {
        this.threshold = threshold;
        this.effect = effect;
    }

    __call__(state: SystemState): void {
        if (state.temp > this.threshold) {
            this.effect(state);
        }
    }
}

function apply_effect(state: SystemState): void {
    state.update(-10, 5, -2);
}

function main(): void {
    const initial_state = new SystemState(300, 101325, 0.5);
    const simulation = new Simulation(initial_state);
    const condition = new BoundaryCondition(350, apply_effect);
    simulation.add_condition(condition);
    simulation.run();
}

main();