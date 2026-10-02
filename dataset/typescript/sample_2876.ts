function state_transition(state: number, data: number): number {
    if (state === 0) {
        return data === 1 ? 1 : 0;
    } else if (state === 1) {
        return data === 2 ? 2 : 1;
    } else if (state === 2) {
        return data === 3 ? 0 : 2;
    }
}

function process_data(sequence: number[]): void {
    let state = 0;
    while (true) {
        for (const data of sequence) {
            state = state_transition(state, data);
        }
    }
}

function main(): void {
    const sequence = [1, 2, 3, 1, 2, 3, 1, 2, 3];
    process_data(sequence);
}

main();