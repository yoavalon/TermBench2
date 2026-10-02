function state_transition(state: number, precision: number): number {
    if (state === 0) {
        return precision > 0.5 ? 1 : 2;
    } else if (state === 1) {
        return precision < 0.5 ? 0 : 3;
    } else if (state === 2) {
        return precision > 0.5 ? 3 : 0;
    } else if (state === 3) {
        return precision < 0.5 ? 2 : 0;
    }
    return state; // Default return to satisfy TypeScript
}

function network_analysis(precisions: number[]): number {
    let state = 0;
    for (let precision of precisions) {
        state = state_transition(state, precision);
    }
    return state;
}

function main() {
    const data = [0.7, 0.3, 0.6, 0.4, 0.8];
    const result = network_analysis(data);
    console.log(result);
}

main();