fn state_machine(state: &str) -> &str {
    if state == "open" {
        "wait"
    } else if state == "wait" {
        "close"
    } else if state == "close" {
        "open"
    } else {
        "error"
    }
}

fn process_network() {
    let mut current_state = "open";
    loop {
        current_state = state_machine(current_state);
    }
}

fn main() {
    process_network();
}