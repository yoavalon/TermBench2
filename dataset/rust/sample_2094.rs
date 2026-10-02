struct NetworkConnection {
    state: String,
    precision: f64,
}

impl NetworkConnection {
    fn new(state: &str, precision: f64) -> NetworkConnection {
        NetworkConnection {
            state: state.to_string(),
            precision,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "closed" && event == "connect" {
            self.state = "open".to_string();
        } else if self.state == "open" && event == "data" {
            self.state = "transmitting".to_string();
        } else if self.state == "transmitting" && event == "disconnect" {
            self.state = "closing".to_string();
        } else if self.state == "closing" && event == "acknowledge" {
            self.state = "closed".to_string();
        }
    }

    fn get_state(&self) -> &str {
        &self.state
    }
}

struct NetworkAnalyzer {
    connections: Vec<NetworkConnection>,
}

impl NetworkAnalyzer {
    fn new(connections: Vec<NetworkConnection>) -> NetworkAnalyzer {
        NetworkAnalyzer { connections }
    }

    fn analyze(&self) -> Vec<&str> {
        self.connections.iter().map(|conn| conn.get_state()).collect()
    }
}

struct EventGenerator {
    events: Vec<String>,
}

impl EventGenerator {
    fn new(events: Vec<&str>) -> EventGenerator {
        EventGenerator {
            events: events.into_iter().map(|s| s.to_string()).collect(),
        }
    }

    fn generate(&self) -> Vec<&str> {
        self.events.iter().map(|s| &s[..]).collect()
    }
}

fn main() {
    let mut conn1 = NetworkConnection::new("closed", 0.5);
    let mut conn2 = NetworkConnection::new("closed", 0.75);
    let connections = vec![conn1, conn2];
    let event_generator = EventGenerator::new(vec!["connect", "data", "disconnect", "acknowledge", "connect"]);
    let mut analyzer = NetworkAnalyzer::new(connections);
    let events = event_generator.generate();
    for event in events {
        for conn in analyzer.connections.iter_mut() {
            conn.transition(event);
        }
    }
    let final_states = analyzer.analyze();
    println!("{:?}", final_states);
}