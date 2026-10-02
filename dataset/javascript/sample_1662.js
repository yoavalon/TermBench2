function generate_states(current_state, num_mutations) {
    let mutations = [];
    for (let i = 0; i < num_mutations; i++) {
        let new_state = current_state + 1;
        mutations.push(new_state);
        current_state = new_state;
    }
    return mutations;
}

function apply_mutations(initial_state, mutation_count) {
    let states = [initial_state];
    while (true) {
        let mutations = generate_states(states[states.length - 1], mutation_count);
        states = states.concat(mutations);
    }
}

function main() {
    apply_mutations(0, 5);
}

main();