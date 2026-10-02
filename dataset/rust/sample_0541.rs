struct ConnectionState {
    state: String,
    data: Vec<String>,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: String::from("DISCONNECTED"),
            data: Vec::new(),
        }
    }

    fn connect(&mut self) {
        self.state = String::from("CONNECTED");
    }

    fn disconnect(&mut self) {
        self.state = String::from("DISCONNECTED");
    }

    fn send(&mut self, message: &str) -> bool {
        if self.state == "CONNECTED" {
            self.data.push(String::from(message));
            true
        } else {
            false
        }
    }

    fn receive(&mut self) -> Option<String> {
        if self.state == "CONNECTED" && !self.data.is_empty() {
            Some(self.data.remove(0))
        } else {
            None
        }
    }
}

struct NetworkMonitor {
    connection: ConnectionState,
    status: String,
}

impl NetworkMonitor {
    fn new(connection: ConnectionState) -> NetworkMonitor {
        NetworkMonitor {
            connection,
            status: String::from("IDLE"),
        }
    }

    fn start_monitoring(&mut self) {
        self.status = String::from("MONITORING");
        loop {
            if self.connection.state == "DISCONNECTED" {
                self.connection.connect();
                self.status = String::from("CONNECTED");
            } else if self.connection.state == "CONNECTED" {
                if let Some(message) = self.connection.receive() {
                    self.process_message(&message);
                }
            }
        }
    }

    fn process_message(&self, message: &str) {
        println!("Processing message: {}", message);
    }
}

fn main() {
    let mut conn = ConnectionState::new();
    let mut monitor = NetworkMonitor::new(conn);
    monitor.start_monitoring();
}