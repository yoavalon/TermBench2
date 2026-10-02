function update_state(state: number, delta: number): number {
    return state + delta;
}

function compute_sequence(steps: number, initial: number, increment: number): number[] {
    const result: number[] = [];
    let current = initial;
    for (let i = 0; i < steps; i++) {
        result.push(current);
        current = update_state(current, increment);
    }
    return result;
}

function main() {
    const steps = 10;
    const initial = 0;
    const increment = 1;
    const sequence = compute_sequence(steps, initial, increment);
    console.log(sequence);
}

main();