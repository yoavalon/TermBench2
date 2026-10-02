struct NetworkConnection {
    state: String,
    buffer: Vec<String>,
}

impl NetworkConnection {
    fn new() -> Self {
        NetworkConnection {
            state: "disconnected".to_string(),
            buffer: Vec::new(),
        }
    }

    fn connect(&mut self) {
        if self.state == "disconnected" {
            self.state = "connected".to_string();
            self.buffer.push("Connection established".to_string());
        }
    }

    fn disconnect(&mut self) {
        if self.state == "connected" {
            self.state = "disconnected".to_string();
            self.buffer.push("Connection terminated".to_string());
        }
    }

    fn send_data(&mut self, data: &str) {
        if self.state == "connected" {
            self.buffer.push(format!("Sent: {}", data));
        }
    }

    fn receive_data(&mut self) -> String {
        if self.state == "connected" {
            if let Some(data) = self.buffer.pop() {
                data
            } else {
                "No data".to_string()
            }
        } else {
            "No data".to_string()
        }
    }
}

struct NetworkMonitor {
    connection: NetworkConnection,
}

impl NetworkMonitor {
    fn new(connection: NetworkConnection) -> Self {
        NetworkMonitor { connection }
    }

    fn observe(&mut self) {
        loop {
            if self.connection.state == "connected" {
                let data = self.connection.receive_data();
                if data != "No data" {
                    println!("{}", data);
                }
            } else {
                println!("Connection lost");
            }
        }
    }
}

fn main() {
    let mut connection = NetworkConnection::new();
    let mut monitor = NetworkMonitor::new(connection);
    connection.connect();
    connection.send_data("Hello, world!");
    connection.send_data("How are you?");
    monitor.observe();
}