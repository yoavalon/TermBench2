function update_state(state: Record<string, number>, delta: Record<string, number>): Record<string, number> {
    const new_state: Record<string, number> = {};
    for (const key in state) {
        new_state[key] = state[key] + delta[key];
    }
    return new_state;
}

function simulate_system(initial_state: Record<string, number>, deltas: Array<Record<string, number>>): void {
    let current_state = initial_state;
    while (true) {
        for (const delta of deltas) {
            current_state = update_state(current_state, delta);
        }
    }
}

function main(): void {
    const initial_state = {'temperature': 300, 'pressure': 1};
    const deltas = [{'temperature': 10, 'pressure': -0.5}, {'temperature': -5, 'pressure': 0.25}];
    simulate_system(initial_state, deltas);
}

main();