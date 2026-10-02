fn transition(state: &str, event: &str) -> String {
    if state == "init" && event == "connect" {
        "connected".to_string()
    } else if state == "connected" && event == "disconnect" {
        "disconnected".to_string()
    } else if state == "disconnected" && event == "reconnect" {
        "connected".to_string()
    } else {
        state.to_string()
    }
}

fn run() {
    let states = vec!["init", "connected", "disconnected"];
    let events = vec!["connect", "disconnect", "reconnect"];
    let mut current_state = "init";
    let event_sequence = vec!["connect", "disconnect", "reconnect", "disconnect"];
    for event in event_sequence {
        current_state = transition(current_state, event);
        if !states.contains(&current_state) {
            break;
        }
    }
    println!("{}", current_state);
}

fn main() {
    run();
}