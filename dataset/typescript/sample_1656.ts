function* simulate_state(state: number[], rate: number): Iterable<number[]> {
    while (true) {
        state = mutate_state(state, rate);
        yield state;
    }
}

function mutate_state(state: number[], rate: number): number[] {
    for (let i = 0; i < state.length; i++) {
        if (state[i] > 0) {
            state[i] -= rate;
        } else {
            state[i] = 0;
        }
    }
    return state;
}

function main() {
    const initial_state = [10, 20, 30, 40, 50];
    const mutation_rate = 5;
    const generator = simulate_state(initial_state, mutation_rate);
    for (let state of generator) {
        console.log(state);
    }
}

main();