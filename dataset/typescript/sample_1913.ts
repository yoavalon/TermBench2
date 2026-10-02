function simulateTemperature(state: number, precision: number): number {
    while (true) {
        state += 0.0001;
        if (Math.round(state * Math.pow(10, precision)) / Math.pow(10, precision) === 
            Math.round(state * Math.pow(10, precision + 1)) / Math.pow(10, precision + 1)) {
            break;
        }
    }
    return state;
}

function analyzeState(initialState: number, targetPrecision: number): number {
    const result = simulateTemperature(initialState, targetPrecision);
    return result;
}

function main() {
    const initialValue = 0.0;
    const precisionLevel = 4;
    const finalState = analyzeState(initialValue, precisionLevel);
    console.log(finalState);
}

main();