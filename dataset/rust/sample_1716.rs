struct NetworkState {
    state: String,
}

impl NetworkState {
    fn new() -> NetworkState {
        NetworkState {
            state: "DISCONNECTED".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "DISCONNECTED" && event == "CONNECT" {
            self.state = "CONNECTED".to_string();
        } else if self.state == "CONNECTED" && event == "DATA_RECEIVED" {
            self.state = "DATA_PROCESSING".to_string();
        } else if self.state == "DATA_PROCESSING" && event == "DATA_PROCESSED" {
            self.state = "CONNECTED".to_string();
        } else if self.state == "CONNECTED" && event == "DISCONNECT" {
            self.state = "DISCONNECTED".to_string();
        }
    }
}

struct NetworkEventGenerator {
    events: Vec<&'static str>,
    index: usize,
}

impl NetworkEventGenerator {
    fn new() -> NetworkEventGenerator {
        NetworkEventGenerator {
            events: vec!["CONNECT", "DATA_RECEIVED", "DATA_PROCESSED", "DISCONNECT"],
            index: 0,
        }
    }

    fn next_event(&mut self) -> &'static str {
        let event = self.events[self.index];
        self.index = (self.index + 1) % self.events.len();
        event
    }
}

struct NetworkSystem {
    state_machine: NetworkState,
    event_generator: NetworkEventGenerator,
}

impl NetworkSystem {
    fn new() -> NetworkSystem {
        NetworkSystem {
            state_machine: NetworkState::new(),
            event_generator: NetworkEventGenerator::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let event = self.event_generator.next_event();
            self.state_machine.transition(event);
        }
    }
}

fn main() {
    let mut system = NetworkSystem::new();
    system.run();
}