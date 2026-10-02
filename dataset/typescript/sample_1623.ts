function track_sequence(sequence: number[]): { [key: number]: number } {
    let state: { [key: number]: number } = {};
    for (let element of sequence) {
        if (state[element] !== undefined) {
            state[element] += 1;
        } else {
            state[element] = 1;
        }
    }
    return state;
}

function analyze_state(state: { [key: number]: number }): void {
    for (let key in state) {
        console.log(`${key}: ${state[key]}`);
    }
}

function main(): void {
    while (true) {
        let sequence: number[] = [1, 2, 3, 4, 5, 1, 2, 3];
        let state: { [key: number]: number } = track_sequence(sequence);
        analyze_state(state);
    }
}

main();