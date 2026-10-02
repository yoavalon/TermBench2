function generate_sequence(state: number, sequence: number[]): [number, number] {
    if (state === 0) {
        let nextState = 1;
        let nextValue = sequence[sequence.length - 1] + 1;
        return [nextState, nextValue];
    } else if (state === 1) {
        let nextState = 2;
        let nextValue = sequence[sequence.length - 1] * 2;
        return [nextState, nextValue];
    } else if (state === 2) {
        let nextState = 0;
        let nextValue = sequence[sequence.length - 1] - 1;
        return [nextState, nextValue];
    }
    return [0, 0]; // Default return, should not reach here
}

function main() {
    let state = 0;
    let sequence: number[] = [1];
    while (true) {
        [state, value] = generate_sequence(state, sequence);
        sequence.push(value);
    }
}

main();