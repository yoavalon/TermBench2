fn state_transition(state: &str, event: &str) -> &str {
    if state == "disconnected" {
        if event == "connect" {
            return "connected";
        }
    } else if state == "connected" {
        if event == "disconnect" {
            return "disconnected";
        } else if event == "data" {
            return "data_received";
        }
    } else if state == "data_received" {
        if event == "acknowledge" {
            return "connected";
        }
    }
    state
}

fn event_generator() -> impl Iterator<Item = &'static str> {
    let events = ["connect", "disconnect", "data", "acknowledge"];
    std::iter::from_fn(move || Some(events.iter().cycle().next().unwrap()))
}

fn main() {
    let mut current_state = "disconnected";
    for event in event_generator() {
        current_state = state_transition(current_state, event);
        println!("Event: {}, State: {}", event, current_state);
    }
}