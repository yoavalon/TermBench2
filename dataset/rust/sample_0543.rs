struct StateMachine {
    state: String,
    connection: Option<String>,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
            connection: None,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
            self.connection = Some("active".to_string());
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "idle".to_string();
            self.connection = None;
        } else if self.state == "connected" && event == "data" {
            self.process_data();
        } else if self.state == "idle" && event == "data" {
            // Do nothing
        }
    }

    fn process_data(&self) {
        println!("Processing data in state: {}", self.state);
    }
}

struct EventGenerator {
    events: Vec<String>,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec![
                "connect".to_string(),
                "data".to_string(),
                "disconnect".to_string(),
                "data".to_string(),
                "connect".to_string(),
                "data".to_string(),
                "disconnect".to_string(),
            ],
        }
    }

    fn generate(&mut self) -> String {
        if let Some(event) = self.events.pop() {
            event
        } else {
            "idle".to_string()
        }
    }
}

struct NetworkManager {
    state_machine: StateMachine,
    event_generator: EventGenerator,
}

impl NetworkManager {
    fn new() -> Self {
        NetworkManager {
            state_machine: StateMachine::new(),
            event_generator: EventGenerator::new(),
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
    let mut network_manager = NetworkManager::new();
    network_manager.run();
}