fn process_connection(state: &str, event: &str) -> &str {
    if state == "idle" && event == "connect" {
        "connected"
    } else if state == "connected" && event == "data" {
        "data_received"
    } else if state == "data_received" && event == "disconnect" {
        "disconnected"
    } else {
        state
    }
}

fn manage_state_machine() {
    let mut state = "idle";
    let events = ["connect", "data", "disconnect"];
    for event in events.iter() {
        state = process_connection(state, event);
        if state == "disconnected" {
            break;
        }
    }
}

fn main() {
    manage_state_machine();
}