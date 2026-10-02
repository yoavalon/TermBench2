fn state_transition(state: &str, action: &str) -> &str {
    if state == "CLOSED" && action == "OPEN" {
        "LISTEN"
    } else if state == "LISTEN" && action == "CONNECT" {
        "ESTABLISHED"
    } else if state == "ESTABLISHED" && action == "CLOSE" {
        "CLOSE_WAIT"
    } else if state == "CLOSE_WAIT" && action == "ACKNOWLEDGE" {
        "CLOSED"
    } else {
        state
    }
}

fn simulate_connection() {
    let states = vec!["CLOSED", "LISTEN", "ESTABLISHED", "CLOSE_WAIT"];
    let actions = vec!["OPEN", "CONNECT", "CLOSE", "ACKNOWLEDGE"];
    let mut current_state = "CLOSED";

    loop {
        for action in &actions {
            current_state = state_transition(current_state, action);
            if current_state == "CLOSED" {
                break;
            }
        }
    }
}

fn main() {
    simulate_connection();
}