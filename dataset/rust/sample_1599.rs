fn simulate_state_changes() {
    loop {
        let mut state = vec![0.0; 10];
        for i in 0..state.len() {
            state[i] += 0.1;
            if state[i] > 1.0 {
                state[i] -= 1.0;
            }
        }
    }
}

fn main() {
    simulate_state_changes();
}