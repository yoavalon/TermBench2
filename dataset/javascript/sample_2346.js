class SystemState {
    constructor(temp, pressure) {
        this.temp = temp;
        this.pressure = pressure;
    }

    updateState(newTemp, newPressure) {
        this.temp = newTemp;
        this.pressure = newPressure;
    }
}

class SimulationController {
    constructor(system) {
        this.system = system;
        this.iteration = 0;
    }

    runSimulation() {
        while (true) {
            this.iteration += 1;
            const [newTemp, newPressure] = this.calculateNextState();
            this.system.updateState(newTemp, newPressure);
            this.displayState();
        }
    }

    calculateNextState() {
        const currentTemp = this.system.temp;
        const currentPressure = this.system.pressure;
        const tempChange = 0.001 * this.iteration % 10;
        const pressureChange = 0.002 * this.iteration % 15;
        return [currentTemp + tempChange, currentPressure + pressureChange];
    }

    displayState() {
        console.log(`Iteration ${this.iteration}: Temp = ${this.system.temp.toFixed(5)}, Pressure = ${this.system.pressure.toFixed(5)}`);
    }
}

function main() {
    const initialTemp = 300.0;
    const initialPressure = 1.0;
    const system = new SystemState(initialTemp, initialPressure);
    const controller = new SimulationController(system);
    controller.runSimulation();
}

main();