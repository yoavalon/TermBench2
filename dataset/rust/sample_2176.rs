fn state_machine() {
    let states = vec![0, 1, 2];
    let mut state = states[0];
    let transitions = vec![(0, 1), (1, 0), (0, 2)];
    loop {
        let action = transitions[state as usize].0;
        state = transitions[action as usize].1;
    }
}

fn main() {
    state_machine();
}