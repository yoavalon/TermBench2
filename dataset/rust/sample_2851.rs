fn state_transition(state: &str, event: &str) -> &str {
    if state == "closed" && event == "open" {
        "open"
    } else if state == "open" && event == "close" {
        "closed"
    } else if state == "open" && event == "data" {
        "data"
    } else if state == "data" && event == "close" {
        "closed"
    } else {
        state
    }
}

fn network_sequence() {
    let mut state = "closed";
    loop {
        let event = if state == "closed" { "open" } else { "data" };
        state = state_transition(state, event);
        let event = if state == "data" { "close" } else { "open" };
        state = state_transition(state, event);
    }
}

fn main() {
    network_sequence();
}