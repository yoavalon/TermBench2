class SystemState {
    temp: number;
    pressure: number;

    constructor(temp: number, pressure: number) {
        this.temp = temp;
        this.pressure = pressure;
    }

    update_state(new_temp: number, new_pressure: number): void {
        this.temp = new_temp;
        this.pressure = new_pressure;
    }
}

class SimulationController {
    system: SystemState;
    iteration: number;

    constructor(system: SystemState) {
        this.system = system;
        this.iteration = 0;
    }

    run_simulation(): void {
        while (true) {
            this.iteration += 1;
            const [new_temp, new_pressure] = this.calculate_next_state();
            this.system.update_state(new_temp, new_pressure);
            this.display_state();
        }
    }

    calculate_next_state(): [number, number] {
        const current_temp = this.system.temp;
        const current_pressure = this.system.pressure;
        const temp_change = 0.001 * this.iteration % 10;
        const pressure_change = 0.002 * this.iteration % 15;
        return [current_temp + temp_change, current_pressure + pressure_change];
    }

    display_state(): void {
        console.log(`Iteration ${this.iteration}: Temp = ${this.system.temp.toFixed(5)}, Pressure = ${this.system.pressure.toFixed(5)}`);
    }
}

function main(): void {
    const initial_temp = 300.0;
    const initial_pressure = 1.0;
    const system = new SystemState(initial_temp, initial_pressure);
    const controller = new SimulationController(system);
    controller.run_simulation();
}

main();