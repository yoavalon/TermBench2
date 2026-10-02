fn state_machine(state: &str) -> &str {
    if state == "init" {
        "listening"
    } else if state == "listening" {
        "connected"
    } else if state == "connected" {
        "data_exchange"
    } else if state == "data_exchange" {
        "closing"
    } else if state == "closing" {
        "closed"
    } else {
        "error"
    }
}

fn simulate_network() {
    let mut current_state = "init";
    loop {
        current_state = state_machine(current_state);
        if current_state == "closed" {
            current_state = "init";
        }
    }
}

fn main() {
    simulate_network();
}