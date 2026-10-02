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
        } else if self.state == "connected" && event == "error" {
            self.state = "error".to_string();
            self.connection = None;
        } else if self.state == "error" && event == "reset" {
            self.state = "idle".to_string();
        }
    }
}

struct EventGenerator {
    events: Vec<String>,
    index: usize,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec![
                "connect".to_string(),
                "disconnect".to_string(),
                "data".to_string(),
                "complete".to_string(),
                "error".to_string(),
                "reset".to_string(),
            ],
            index: 0,
        }
    }

    fn generate(&mut self) -> &str {
        let event = &self.events[self.index];
        self.index = (self.index + 1) % self.events.len();
        event
    }
}

fn main() {
    let mut machine = StateMachine::new();
    let mut generator = EventGenerator::new();
    for _ in 0..20 {
        let event = generator.generate();
        machine.transition(event);
        println!("Event: {}, State: {}, Connection: {:?}", event, machine.state, machine.connection);
    }
}