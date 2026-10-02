fn transition(state: &str, event: &str) -> &str {
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

fn process_events(events: Vec<&str>) -> &str {
    let mut current_state = "idle";
    for event in events {
        current_state = transition(current_state, event);
        if current_state == "disconnected" {
            break;
        }
    }
    current_state
}

fn main() {
    let events = vec!["connect", "data", "disconnect", "connect"];
    let final_state = process_events(events);
    println!("{}", final_state);
}