struct NetworkState {
    state: String,
}

impl NetworkState {
    fn new(state: &str) -> NetworkState {
        NetworkState {
            state: state.to_string(),
        }
    }

    fn transition(&self, event: &str) -> String {
        match (&self.state, event) {
            ("DISCONNECTED", "CONNECT") => "CONNECTED".to_string(),
            ("CONNECTED", "DISCONNECT") => "DISCONNECTED".to_string(),
            ("CONNECTED", "RECEIVE") => "PROCESSING".to_string(),
            ("PROCESSING", "SEND") => "CONNECTED".to_string(),
            _ => self.state.clone(),
        }
    }
}

struct NetworkStateMachine {
    current_state: NetworkState,
}

impl NetworkStateMachine {
    fn new() -> NetworkStateMachine {
        NetworkStateMachine {
            current_state: NetworkState::new("DISCONNECTED"),
        }
    }

    fn process_event(&mut self, event: &str) -> String {
        let new_state = self.current_state.transition(event);
        self.current_state = NetworkState::new(&new_state);
        new_state
    }
}

fn generate_events() -> Vec<String> {
    let events = vec!["CONNECT".to_string(), "RECEIVE".to_string(), "SEND".to_string(), "DISCONNECT".to_string()];
    events.repeat(10)
}

fn simulate_network() {
    let mut state_machine = NetworkStateMachine::new();
    let events = generate_events();
    let mut index = 0;
    loop {
        let event = &events[index % events.len()];
        let new_state = state_machine.process_event(event);
        index += 1;
        if new_state == "PROCESSING" {
            simulate_network();
        }
    }
}

fn main() {
    simulate_network();
}