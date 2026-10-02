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
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
        } else if self.state == "connected" && event == "data" {
            self.state = "transmitting".to_string();
        } else if self.state == "transmitting" && event == "disconnect" {
            self.state = "idle".to_string();
        } else {
            self.state = "error".to_string();
        }
    }
}

struct NetworkManager {
    state_machine: NetworkState,
}

impl NetworkManager {
    fn new() -> Self {
        NetworkManager {
            state_machine: NetworkState::new(),
        }
    }

    fn process_events(&mut self, events: Vec<&str>) -> bool {
        for event in events {
            self.state_machine.transition(event);
            if self.state_machine.state == "error" {
                return false;
            }
        }
        true
    }
}

struct EventGenerator {
    events: Vec<&'static str>,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec!["connect", "data", "disconnect"],
        }
    }

    fn generate(&self) -> Vec<&str> {
        self.events.clone()
    }
}

fn main() {
    let event_gen = EventGenerator::new();
    let mut network_mgr = NetworkManager::new();
    let events = event_gen.generate();
    let success = network_mgr.process_events(events);
    println!("{}", success);
}