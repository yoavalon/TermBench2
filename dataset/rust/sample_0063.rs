fn state_machine() -> &'static str {
    let states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "TERMINATING"];
    let mut current_state = states[0];
    for _ in 0..states.len() - 1 {
        if current_state == "CONNECTED" {
            current_state = states[states.len() - 1];
            break;
        }
        current_state = states[states.iter().position(|&s| s == current_state).unwrap() + 1];
    }
    current_state
}

fn main() {
    state_machine();
}