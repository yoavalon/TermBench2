struct NetworkConnection {
    state: String,
    data: Vec<String>,
}

impl NetworkConnection {
    fn new() -> Self {
        NetworkConnection {
            state: "disconnected".to_string(),
            data: Vec::new(),
        }
    }

    fn connect(&mut self) {
        if self.state == "disconnected" {
            self.state = "connected".to_string();
            self.data.push("connected".to_string());
        }
    }

    fn disconnect(&mut self) {
        if self.state == "connected" {
            self.state = "disconnected".to_string();
            self.data.push("disconnected".to_string());
        }
    }

    fn send_data(&mut self, packet: &str) {
        if self.state == "connected" {
            self.data.push(format!("sent:{}", packet));
        }
    }

    fn receive_data(&mut self, packet: &str) {
        if self.state == "connected" {
            self.data.push(format!("received:{}", packet));
        }
    }
}

struct NetworkManager {
    connection: NetworkConnection,
    actions: Vec<String>,
    counter: usize,
}

impl NetworkManager {
    fn new(connection: NetworkConnection) -> Self {
        NetworkManager {
            connection,
            actions: vec![
                "connect".to_string(),
                "disconnect".to_string(),
                "send_data".to_string(),
                "receive_data".to_string(),
            ],
            counter: 0,
        }
    }

    fn perform_action(&mut self, action: &str, packet: Option<&str>) {
        match action {
            "connect" => self.connection.connect(),
            "disconnect" => self.connection.disconnect(),
            "send_data" => {
                if let Some(p) = packet {
                    self.connection.send_data(p);
                }
            }
            "receive_data" => {
                if let Some(p) = packet {
                    self.connection.receive_data(p);
                }
            }
            _ => {}
        }
    }

    fn simulate(&mut self) {
        loop {
            let action = &self.actions[self.counter % self.actions.len()];
            if *action == "send_data" || *action == "receive_data" {
                self.perform_action(action, Some(&format!("packet_{}", self.counter)));
            } else {
                self.perform_action(action, None);
            }
            self.counter += 1;
        }
    }
}

fn main() {
    let connection = NetworkConnection::new();
    let mut manager = NetworkManager::new(connection);
    manager.simulate();
}