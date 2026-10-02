struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new(state: &str) -> ConnectionState {
        ConnectionState {
            state: state.to_string(),
        }
    }

    fn transition(&self) -> ConnectionState {
        match self.state.as_str() {
            "CONNECTING" => ConnectionState::new("OPEN"),
            "OPEN" => ConnectionState::new("CLOSED"),
            "CLOSED" => ConnectionState::new("RECONNECTING"),
            _ => ConnectionState::new("CONNECTING"),
        }
    }
}

struct NetworkMonitor {
    state: ConnectionState,
}

impl NetworkMonitor {
    fn new() -> NetworkMonitor {
        NetworkMonitor {
            state: ConnectionState::new("CONNECTING"),
        }
    }

    fn monitor(&mut self) {
        loop {
            self.state = self.state.transition();
            self.process_state();
        }
    }

    fn process_state(&self) {
        match self.state.state.as_str() {
            "OPEN" => self.handle_open(),
            "CLOSED" => self.handle_closed(),
            "RECONNECTING" => self.handle_reconnecting(),
            _ => {}
        }
    }

    fn handle_open(&self) {}

    fn handle_closed(&self) {}

    fn handle_reconnecting(&self) {}
}

fn main() {
    let mut monitor = NetworkMonitor::new();
    monitor.monitor();
}