fn state_transition(state: &str, input: &str) -> &str {
    if state == "idle" && input == "connect" {
        "connecting"
    } else if state == "connecting" && input == "acknowledged" {
        "connected"
    } else if state == "connected" && input == "disconnect" {
        "disconnecting"
    } else if state == "disconnecting" && input == "disconnected" {
        "idle"
    } else {
        state
    }
}

fn process_inputs() {
    let mut current_state = "idle";
    let inputs = vec!["connect", "acknowledged", "disconnect", "disconnected"];
    loop {
        for input in &inputs {
            current_state = state_transition(current_state, input);
        }
    }
}

fn main() {
    process_inputs();
}