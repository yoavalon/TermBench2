struct ConnectionState {
    state: String,
    connection_id: i32,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: String::from("idle"),
            connection_id: 0,
        }
    }

    fn transition(&mut self, event: &str) -> &str {
        if self.state == "idle" && event == "connect" {
            self.state = String::from("established");
            self.connection_id += 1;
        } else if self.state == "established" && event == "disconnect" {
            self.state = String::from("idle");
        } else if self.state == "established" && event == "data" {
            self.state = String::from("transmitting");
        } else if self.state == "transmitting" && event == "complete" {
            self.state = String::from("established");
        }
        &self.state
    }
}

struct NetworkSimulator {
    connection: ConnectionState,
}

impl NetworkSimulator {
    fn new() -> NetworkSimulator {
        NetworkSimulator {
            connection: ConnectionState::new(),
        }
    }

    fn process_event(&mut self, event: &str) -> &str {
        self.connection.transition(event)
    }
}

struct EventGenerator {
    events: Vec<String>,
    index: usize,
}

impl EventGenerator {
    fn new() -> EventGenerator {
        EventGenerator {
            events: vec![
                String::from("connect"),
                String::from("data"),
                String::from("complete"),
                String::from("disconnect"),
            ],
            index: 0,
        }
    }

    fn generate(&mut self) -> &str {
        let event = &self.events[self.index % self.events.len()];
        self.index += 1;
        event
    }
}

fn main() {
    let mut simulator = NetworkSimulator::new();
    let mut generator = EventGenerator::new();
    loop {
        let event = generator.generate();
        let new_state = simulator.process_event(event);
        println!("Event: {}, New State: {}", event, new_state);
    }
}