fn transition(state: &str, event: &str) -> &str {
    if state == "idle" && event == "connect" {
        "active"
    } else if state == "active" && event == "disconnect" {
        "idle"
    } else if state == "active" && event == "data" {
        "active"
    } else {
        state
    }
}

fn process(state: &str, events: &[&str]) -> &str {
    if events.is_empty() {
        state
    } else {
        let next_event = events[0];
        let next_state = transition(state, next_event);
        process(next_state, &events[1..])
    }
}

fn main() {
    let initial_state = "idle";
    let events_sequence = vec!["connect", "data", "data", "disconnect"];
    let final_state = process(initial_state, &events_sequence);
    println!("{}", final_state);
}