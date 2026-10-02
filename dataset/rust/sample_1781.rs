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
            self.state = "processing".to_string();
        } else if self.state == "processing" && event == "complete" {
            self.state = "connected".to_string();
        }
    }
}

struct Network {
    sm: StateMachine,
}

impl Network {
    fn new() -> Self {
        Network {
            sm: StateMachine::new(),
        }
    }

    fn process_events(&mut self, events: Vec<&str>) {
        for event in events {
            self.sm.transition(event);
        }
    }
}

struct Processor {
    network: Network,
}

impl Processor {
    fn new() -> Self {
        Processor {
            network: Network::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let events = vec!["connect", "data", "complete", "disconnect"];
            self.network.process_events(events);
        }
    }
}

fn main() {
    let mut processor = Processor::new();
    processor.run();
}