fn state_transition(state: &str, event: &str) -> String {
    if state == "disconnected" && event == "connect" {
        "connected".to_string()
    } else if state == "connected" && event == "disconnect" {
        "disconnected".to_string()
    } else if state == "connected" && event == "data_received" {
        "processing".to_string()
    } else if state == "processing" && event == "data_processed" {
        "connected".to_string()
    } else {
        state.to_string()
    }
}

fn simulate_network() {
    let mut current_state = "disconnected";
    let events = vec!["connect", "data_received", "data_processed", "disconnect"];
    let mut index = 0;
    loop {
        current_state = state_transition(current_state, events[index % events.len()]);
        index += 1;
    }
}

fn main() {
    simulate_network();
}