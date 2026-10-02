function cellular_automata(state, rule) {
    let size = state.length;
    let next_state = new Array(size).fill(0);
    for (let i = 0; i < size; i++) {
        let left = state[(i - 1 + size) % size];
        let center = state[i];
        let right = state[(i + 1) % size];
        let index = (left << 2) | (center << 1) | right;
        next_state[i] = (rule >> index) & 1;
    }
    return cellular_automata(next_state, rule);
}
let rule = 30;
let initial_state = new Array(10).fill(0).concat(1).concat(new Array(10).fill(0));
cellular_automata(initial_state, rule);