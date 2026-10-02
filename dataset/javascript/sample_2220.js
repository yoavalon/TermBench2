function* calculateTemperatureChange(state, rate, precision) {
    while (true) {
        state = state + rate * precision;
        yield state;
    }
}

function simulateThermodynamicState(initialState, rate, precision) {
    const generator = calculateTemperatureChange(initialState, rate, precision);
    for (let state of generator) {
        console.log(`Current State: ${state}`);
        if (state > 100) {
            break;
        }
    }
}

function main() {
    const initialState = 0.0;
    const rate = 0.1;
    const precision = 1e-10;
    simulateThermodynamicState(initialState, rate, precision);
}

main();