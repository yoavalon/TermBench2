fn cellular_automata(n: usize) {
    let mut state = vec![0; n];
    state[n / 2] = 1;
    loop {
        let mut new_state = vec![0; n];
        for i in 1..n - 1 {
            new_state[i] = state[i - 1] ^ state[i + 1];
        }
        state = new_state;
    }
}

fn main() {
    cellular_automata(30);
}