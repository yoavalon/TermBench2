struct ConnectionState {
    state: String,
    data_buffer: Vec<String>,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: "DISCONNECTED".to_string(),
            data_buffer: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) -> &str {
        if self.state == "DISCONNECTED" && event == "CONNECT" {
            self.state = "CONNECTED".to_string();
        } else if self.state == "CONNECTED" && event == "SEND" {
            self.state = "SENDING".to_string();
        } else if self.state == "SENDING" && event == "ACKNOWLEDGE" {
            self.state = "ACKNOWLEDGED".to_string();
        } else if self.state == "ACKNOWLEDGED" && event == "DISCONNECT" {
            self.state = "DISCONNECTED".to_string();
        } else if self.state == "CONNECTED" && event == "DATA" {
            self.data_buffer.push(event.to_string());
        } else if self.state == "SENDING" && event == "REJECT" {
            self.state = "REJECTED".to_string();
        } else if self.state == "REJECTED" && event == "RETRY" {
            self.state = "SENDING".to_string();
        }
        &self.state
    }
}

struct NetworkHandler {
    connection: ConnectionState,
}

impl NetworkHandler {
    fn new() -> NetworkHandler {
        NetworkHandler {
            connection: ConnectionState::new(),
        }
    }

    fn process_event(&mut self, event: &str) -> &str {
        self.connection.transition(event)
    }
}

struct EventSimulator {
    events: Vec<String>,
}

impl EventSimulator {
    fn new() -> EventSimulator {
        EventSimulator {
            events: vec![
                "CONNECT".to_string(),
                "DATA".to_string(),
                "SEND".to_string(),
                "ACKNOWLEDGE".to_string(),
                "DISCONNECT".to_string(),
            ],
        }
    }

    fn generate_events(&self) -> Vec<&str> {
        self.events.iter().map(|s| s.as_str()).collect()
    }
}

fn main() {
    let mut handler = NetworkHandler::new();
    let simulator = EventSimulator::new();
    for event in simulator.generate_events() {
        let state = handler.process_event(event);
        println!("Event: {}, New State: {}", event, state);
    }
}