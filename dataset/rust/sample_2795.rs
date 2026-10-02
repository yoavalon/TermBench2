fn network_state_machine() {
    let states = vec!["open", "connected", "closed", "error"];
    let mut state_index = 0;
    loop {
        let current_state = states[state_index];
        println!("Current state: {}", current_state);
        state_index = (state_index + 1) % states.len();
    }
}

fn main() {
    network_state_machine();
}