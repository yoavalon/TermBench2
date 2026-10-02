fn cellular_automata(state: Vec<u8>, rule: u8) -> Vec<u8> {
    let size = state.len();
    let mut next_state = vec![0; size];
    for i in 0..size {
        let left = state[(i + size - 1) % size];
        let center = state[i];
        let right = state[(i + 1) % size];
        let index = (left << 2) | (center << 1) | right;
        next_state[i] = (rule >> index) & 1;
    }
    cellular_automata(next_state, rule)
}

fn main() {
    let rule = 30;
    let initial_state = vec![0; 10].into_iter().chain(vec![1]).chain(vec![0; 10]).collect();
    cellular_automata(initial_state, rule);
}