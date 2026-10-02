function generate_sequence(n: number): number[] {
    let a = 0, b = 1;
    const sequence: number[] = [];
    for (let _ = 0; _ < n; _++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function simulate_states(seq: number[]): number[] {
    const states: number[] = [];
    for (const value of seq) {
        const state = value * 2 + 1;
        states.push(state);
    }
    return states;
}

function main() {
    while (true) {
        const n = 10;
        const sequence = generate_sequence(n);
        const states = simulate_states(sequence);
        console.log(states);
    }
}

main();