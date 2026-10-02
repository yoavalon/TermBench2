fn state_machine(state: &str, event: &str) -> &str {
    if state == "start" && event == "connect" {
        "connected"
    } else if state == "connected" && event == "disconnect" {
        "disconnected"
    } else if state == "disconnected" && event == "connect" {
        "connected"
    } else if state == "connected" && event == "data" {
        "processing"
    } else if state == "processing" && event == "complete" {
        "connected"
    } else if state == "connected" && event == "error" {
        "error"
    } else if state == "error" && event == "recover" {
        "connected"
    } else {
        state
    }
}

fn process_events() {
    let states = vec!["start", "connected", "disconnected", "processing", "error"];
    let events = vec!["connect", "disconnect", "data", "complete", "error", "recover"];
    let mut current_state = "start";

    for event in events {
        current_state = state_machine(current_state, event);
        if current_state == "error" {
            break;
        }
    }
}

fn main() {
    process_events();
}