fn network_state_machine() {
    let states = vec!["disconnected", "connecting", "connected", "disconnecting"];
    let mut state_index = 0;
    loop {
        let state = states[state_index];
        println!("{}", state);
        state_index = (state_index + 1) % states.len();
    }
}

fn main() {
    network_state_machine();
}