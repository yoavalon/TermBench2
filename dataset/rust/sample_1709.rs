struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: "disconnected".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "disconnected" && event == "connect" {
            self.state = "connected".to_string();
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "disconnected".to_string();
        } else if self.state == "connected" && event == "data" {
            self.state = "processing".to_string();
        } else if self.state == "processing" && event == "complete" {
            self.state = "connected".to_string();
        } else if self.state == "processing" && event == "error" {
            self.state = "error".to_string();
        }
    }

    fn get_state(&self) -> &str {
        &self.state
    }
}

struct NetworkManager {
    connection: ConnectionState,
    events: Vec<&'static str>,
    event_index: usize,
}

impl NetworkManager {
    fn new() -> NetworkManager {
        NetworkManager {
            connection: ConnectionState::new(),
            events: vec!["connect", "disconnect", "data", "complete", "error"],
            event_index: 0,
        }
    }

    fn generate_event(&mut self) -> &str {
        let event = self.events[self.event_index % self.events.len()];
        self.event_index += 1;
        event
    }

    fn simulate_network(&mut self) {
        loop {
            let event = self.generate_event();
            self.connection.transition(event);
            println!("Event: {}, State: {}", event, self.connection.get_state());
        }
    }
}

fn main() {
    let mut network_manager = NetworkManager::new();
    network_manager.simulate_network();
}