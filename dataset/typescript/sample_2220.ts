function* calculateTemperatureChange(state: number, rate: number, precision: number): Generator<number> {
    while (true) {
        state = state + rate * precision;
        yield state;
    }
}

function simulateThermodynamicState(initialState: number, rate: number, precision: number): void {
    for (const state of calculateTemperatureChange(initialState, rate, precision)) {
        console.log(`Current State: ${state}`);
        if (state > 100) {
            break;
        }
    }
}

function main(): void {
    const initialState = 0.0;
    const rate = 0.1;
    const precision = 1e-10;
    simulateThermodynamicState(initialState, rate, precision);
}

main();