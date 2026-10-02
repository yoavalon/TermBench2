function simulate_state(state, rate) {
    while (true) {
        state = mutate_state(state, rate);
        yield state;
    }
}

function mutate_state(state, rate) {
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
    for (;;) {
        const state = generator.next().value;
        console.log(state);
    }
}

main();