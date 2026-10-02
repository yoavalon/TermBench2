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
            self.state = "DATA_RECEIVED".to_string();
        } else if self.state == "DATA_RECEIVED" && event == "ACKNOWLEDGE" {
            self.state = "ACKNOWLEDGED".to_string();
        } else if self.state == "ACKNOWLEDGED" && event == "DISCONNECT" {
            self.state = "DISCONNECTED".to_string();
        }
    }
}

struct EventGenerator;

impl EventGenerator {
    fn generate_events(&self) -> std::iter::Cycle<std::vec::IntoIter<String>> {
        let events = vec![
            "CONNECT".to_string(),
            "DATA".to_string(),
            "ACKNOWLEDGE".to_string(),
            "DISCONNECT".to_string(),
        ];
        events.into_iter().cycle()
    }
}

struct NetworkAnalyzer {
    connection: ConnectionState,
    event_gen: EventGenerator,
}

impl NetworkAnalyzer {
    fn new() -> Self {
        NetworkAnalyzer {
            connection: ConnectionState::new(),
            event_gen: EventGenerator,
        }
    }

    fn analyze(&mut self) {
        for event in self.event_gen.generate_events() {
            self.connection.transition(&event);
            println!("Current state: {}", self.connection.state);
        }
    }
}

fn main() {
    let mut analyzer = NetworkAnalyzer::new();
    analyzer.analyze();
}