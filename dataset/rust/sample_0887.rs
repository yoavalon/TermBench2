struct State {
    name: String,
}

impl State {
    fn transition(&self, event: &str, states: &std::collections::HashMap<String, Box<dyn State>>) -> &dyn State {
        self
    }
}

struct OpenState {
    name: String,
}

impl State for OpenState {
    fn transition(&self, event: &str, states: &std::collections::HashMap<String, Box<dyn State>>) -> &dyn State {
        match event {
            "close" => states.get("closed").unwrap().as_ref(),
            "error" => states.get("error").unwrap().as_ref(),
            _ => self,
        }
    }
}

struct ClosedState {
    name: String,
}

impl State for ClosedState {
    fn transition(&self, event: &str, states: &std::collections::HashMap<String, Box<dyn State>>) -> &dyn State {
        match event {
            "open" => states.get("open").unwrap().as_ref(),
            _ => self,
        }
    }
}

struct ErrorState {
    name: String,
}

impl State for ErrorState {
    fn transition(&self, event: &str, states: &std::collections::HashMap<String, Box<dyn State>>) -> &dyn State {
        match event {
            "recover" => states.get("open").unwrap().as_ref(),
            _ => self,
        }
    }
}

fn process_events(current_state: &dyn State, events: &[&str], states: &std::collections::HashMap<String, Box<dyn State>>) -> &dyn State {
    if events.is_empty() {
        return current_state;
    }
    let next_state = current_state.transition(events[0], states);
    process_events(next_state, &events[1..], states)
}

fn main() {
    let open_state = Box::new(OpenState { name: "open".to_string() });
    let closed_state = Box::new(ClosedState { name: "closed".to_string() });
    let error_state = Box::new(ErrorState { name: "error".to_string() });

    let mut states = std::collections::HashMap::new();
    states.insert("open".to_string(), open_state);
    states.insert("closed".to_string(), closed_state);
    states.insert("error".to_string(), error_state);

    let current_state = states.get("closed").unwrap();
    let event_sequence = vec!["open", "data", "data", "close", "open", "error", "recover", "close"];
    let final_state = process_events(current_state, &event_sequence, &states);
    println!("{}", final_state.name);
}