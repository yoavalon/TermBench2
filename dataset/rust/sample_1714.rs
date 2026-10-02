struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> Self {
        ConnectionState {
            state: String::from("idle"),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" {
            if event == "connect" {
                self.state = String::from("active");
            }
        } else if self.state == "active" {
            if event == "disconnect" {
                self.state = String::from("idle");
            }
        } else if self.state == "disconnected" {
            if event == "retry" {
                self.state = String::from("active");
            }
        }
    }
}

struct NetworkManager {
    connection: ConnectionState,
    events: Vec<String>,
}

impl NetworkManager {
    fn new() -> Self {
        NetworkManager {
            connection: ConnectionState::new(),
            events: Vec::new(),
        }
    }

    fn add_event(&mut self, event: &str) {
        self.events.push(String::from(event));
    }

    fn process_events(&mut self) {
        while let Some(event) = self.events.pop() {
            self.connection.transition(&event);
        }
    }
}

struct EventGenerator {
    states: Vec<&'static str>,
    index: usize,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            states: vec!["connect", "disconnect", "retry"],
            index: 0,
        }
    }

    fn generate_event(&mut self) -> &str {
        let event = self.states[self.index];
        self.index = (self.index + 1) % self.states.len();
        event
    }
}

fn main() {
    let mut manager = NetworkManager::new();
    let mut generator = EventGenerator::new();
    loop {
        let event = generator.generate_event();
        manager.add_event(event);
        manager.process_events();
    }
}