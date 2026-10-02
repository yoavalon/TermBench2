fn state_machine(state: &str) -> &str {
    if state == "open" {
        "connected"
    } else if state == "connected" {
        "transmitting"
    } else if state == "transmitting" {
        "closed"
    } else if state == "closed" {
        "open"
    } else {
        state
    }
}

fn process(state: &str) {
    let new_state = state_machine(state);
    process(new_state);
}

fn main() {
    let initial_state = "open";
    process(initial_state);
}