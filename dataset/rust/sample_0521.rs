struct NetworkStateMachine {
    state: String,
    events: Vec<String>,
}

impl NetworkStateMachine {
    fn new() -> Self {
        NetworkStateMachine {
            state: "disconnected".to_string(),
            events: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) {
        match (&self.state, event) {
            ("disconnected", "connect") => {
                self.state = "connected".to_string();
                self.events.push(event.to_string());
            }
            ("connected", "disconnect") => {
                self.state = "disconnected".to_string();
                self.events.push(event.to_string());
            }
            ("connected", "data") => {
                self.state = "processing".to_string();
                self.events.push(event.to_string());
            }
            ("processing", "complete") => {
                self.state = "connected".to_string();
                self.events.push(event.to_string());
            }
            _ => {
                self.events.push("invalid".to_string());
            }
        }
    }

    fn get_state(&self) -> &str {
        &self.state
    }

    fn get_events(&self) -> &Vec<String> {
        &self.events
    }
}

struct EventGenerator {
    events: Vec<String>,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec!["connect".to_string(), "data".to_string(), "complete".to_string(), "disconnect".to_string()],
        }
    }

    fn generate(&self) -> String {
        use rand::seq::SliceRandom;
        let mut rng = rand::thread_rng();
        self.events.choose(&mut rng).unwrap().clone()
    }
}

struct SystemMonitor {
    state_machine: NetworkStateMachine,
    event_generator: EventGenerator,
}

impl SystemMonitor {
    fn new(state_machine: NetworkStateMachine, event_generator: EventGenerator) -> Self {
        SystemMonitor {
            state_machine,
            event_generator,
        }
    }

    fn run(&mut self) {
        loop {
            let event = self.event_generator.generate();
            self.state_machine.transition(&event);
        }
    }
}

fn main() {
    let state_machine = NetworkStateMachine::new();
    let event_generator = EventGenerator::new();
    let mut monitor = SystemMonitor::new(state_machine, event_generator);
    monitor.run();
}