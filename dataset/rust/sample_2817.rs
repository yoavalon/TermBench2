fn transition(state: &str, event: &str) -> &str {
    if state == "init" && event == "connect" {
        "connected"
    } else if state == "connected" && event == "disconnect" {
        "disconnected"
    } else if state == "disconnected" && event == "reconnect" {
        "connected"
    } else {
        state
    }
}

fn sequence(event_list: Vec<&str>) {
    let mut current_state = "init";
    loop {
        for event in &event_list {
            current_state = transition(current_state, event);
            println!("{}", current_state);
        }
    }
}

fn main() {
    let events = vec!["connect", "disconnect", "reconnect", "connect", "disconnect"];
    sequence(events);
}