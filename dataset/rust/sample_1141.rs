struct NetworkState {
    state: String,
    buffer: Vec<String>,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: "idle".to_string(),
            buffer: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
            self.buffer.push("connection established".to_string());
        } else if self.state == "connected" && event == "data" {
            self.state = "data_received".to_string();
            self.buffer.push("data received".to_string());
        } else if self.state == "data_received" && event == "disconnect" {
            self.state = "idle".to_string();
            self.buffer.push("disconnected".to_string());
        }
    }
}

struct NetworkHandler {
    machine: NetworkState,
}

impl NetworkHandler {
    fn new(machine: NetworkState) -> Self {
        NetworkHandler { machine }
    }

    fn handle_event(&mut self, event: &str) {
        self.machine.transition(event);
    }
}

struct NetworkMonitor {
    handler: NetworkHandler,
}

impl NetworkMonitor {
    fn new(handler: NetworkHandler) -> Self {
        NetworkMonitor { handler }
    }

    fn monitor(&mut self) {
        let events = vec!["connect", "data", "disconnect"];
        loop {
            for event in &events {
                self.handler.handle_event(event);
            }
        }
    }
}

fn main() {
    let state_machine = NetworkState::new();
    let handler = NetworkHandler::new(state_machine);
    let mut monitor = NetworkMonitor::new(handler);
    monitor.monitor();
}