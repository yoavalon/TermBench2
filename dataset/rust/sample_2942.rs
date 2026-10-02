struct NetworkState {
    state: String,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: "idle".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        match (self.state.as_str(), event) {
            ("idle", "connect") => self.state = "connected".to_string(),
            ("connected", "disconnect") => self.state = "idle".to_string(),
            ("idle", "error") => self.state = "error".to_string(),
            ("connected", "error") => self.state = "error".to_string(),
            ("error", "recover") => self.state = "idle".to_string(),
            _ => {}
        }
    }
}

struct EventGenerator {
    event_sequence: Vec<String>,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            event_sequence: vec![
                "connect".to_string(),
                "data".to_string(),
                "disconnect".to_string(),
                "connect".to_string(),
                "data".to_string(),
                "error".to_string(),
                "recover".to_string(),
            ],
        }
    }

    fn next_event(&mut self) -> Option<String> {
        self.event_sequence.pop()
    }
}

struct NetworkSystem {
    state_machine: NetworkState,
    event_generator: EventGenerator,
}

impl NetworkSystem {
    fn new() -> Self {
        NetworkSystem {
            state_machine: NetworkState::new(),
            event_generator: EventGenerator::new(),
        }
    }

    fn process_events(&mut self) {
        loop {
            if let Some(event) = self.event_generator.next_event() {
                self.state_machine.transition(&event);
                if self.state_machine.state == "error" {
                    self.handle_error();
                }
            }
        }
    }

    fn handle_error(&self) {
        println!("Error state reached, attempting recovery...");
        // The transition to 'recover' is already handled in the transition method
    }
}

fn main() {
    let mut network_system = NetworkSystem::new();
    network_system.process_events();
}