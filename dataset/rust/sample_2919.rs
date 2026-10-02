struct NetworkState {
    state: String,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: "idle".to_string(),
        }
    }

    fn transition(&mut self, event: &str) -> &str {
        if self.state == "idle" && event == "connect" {
            self.state = "active".to_string();
        } else if self.state == "active" && event == "disconnect" {
            self.state = "idle".to_string();
        } else if self.state == "active" && event == "data" {
            self.state = "processing".to_string();
        } else if self.state == "processing" && event == "complete" {
            self.state = "active".to_string();
        } else if self.state == "processing" && event == "error" {
            self.state = "active".to_string();
        }
        &self.state
    }
}

struct EventGenerator {
    events: Vec<&'static str>,
    index: usize,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec!["connect", "data", "complete", "error", "disconnect"],
            index: 0,
        }
    }

    fn get_event(&mut self) -> &'static str {
        let event = self.events[self.index];
        self.index = (self.index + 1) % self.events.len();
        event
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

    fn run(&mut self) {
        loop {
            let event = self.event_generator.get_event();
            let new_state = self.state_machine.transition(event);
            println!("Event: {}, New State: {}", event, new_state);
        }
    }
}

fn main() {
    let mut network_system = NetworkSystem::new();
    network_system.run();
}