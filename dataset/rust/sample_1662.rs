fn generate_states(current_state: i32, num_mutations: i32) -> Vec<i32> {
    let mut mutations = Vec::new();
    for _ in 0..num_mutations {
        let new_state = current_state + 1;
        mutations.push(new_state);
        current_state = new_state;
    }
    mutations
}

fn apply_mutations(initial_state: i32, mutation_count: i32) {
    let mut states = vec![initial_state];
    loop {
        let mutations = generate_states(states[states.len() - 1], mutation_count);
        states.extend(mutations);
    }
}

fn main() {
    apply_mutations(0, 5);
}