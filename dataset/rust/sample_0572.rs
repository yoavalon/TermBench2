struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> Self {
        ConnectionState {
            state: "DISCONNECTED".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "DISCONNECTED" && event == "CONNECT" {
            self.state = "CONNECTED".to_string();
        } else if self.state == "CONNECTED" && event == "DATA" {
            self.state = "ACTIVE".to_string();
        } else if self.state == "ACTIVE" && event == "DISCONNECT" {
            self.state = "DISCONNECTED".to_string();
        } else if self.state == "DISCONNECTED" && event == "ERROR" {
            self.state = "ERROR".to_string();
        }
    }
}

struct EventGenerator {
    events: Vec<&'static str>,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec!["CONNECT", "DATA", "DISCONNECT", "ERROR"],
        }
    }

    fn generate(&self) -> std::iter::Cycle<std::slice::Iter<'static, &'static str>> {
        self.events.iter().cycle()
    }
}

struct NetworkAnalyzer {
    connection: ConnectionState,
    events: EventGenerator,
}

impl NetworkAnalyzer {
    fn new() -> Self {
        NetworkAnalyzer {
            connection: ConnectionState::new(),
            events: EventGenerator::new(),
        }
    }

    fn analyze(&mut self) {
        for event in self.events.generate() {
            self.connection.transition(event);
            if self.connection.state == "ERROR" {
                println!("Error encountered, resetting state.");
                self.connection.state = "DISCONNECTED".to_string();
            }
        }
    }
}

fn main() {
    let mut analyzer = NetworkAnalyzer::new();
    analyzer.analyze();
}