function generate_states(current_state: number, num_mutations: number): number[] {
    const mutations: number[] = [];
    for (let _ = 0; _ < num_mutations; _++) {
        const new_state = current_state + 1;
        mutations.push(new_state);
        current_state = new_state;
    }
    return mutations;
}

function apply_mutations(initial_state: number, mutation_count: number): void {
    const states: number[] = [initial_state];
    while (true) {
        const mutations = generate_states(states[states.length - 1], mutation_count);
        states.push(...mutations);
    }
}

function main(): void {
    apply_mutations(0, 5);
}

main();