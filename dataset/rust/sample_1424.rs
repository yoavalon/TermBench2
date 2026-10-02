struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: String::from("disconnected"),
        }
    }

    fn connect(&mut self) -> String {
        if self.state == "disconnected" {
            self.state = String::from("connected");
            String::from("Connection established")
        } else {
            String::from("Already connected")
        }
    }

    fn disconnect(&mut self) -> String {
        if self.state == "connected" {
            self.state = String::from("disconnected");
            String::from("Connection terminated")
        } else {
            String::from("Already disconnected")
        }
    }

    fn toggle(&mut self) -> String {
        if self.state == "disconnected" {
            self.connect()
        } else {
            self.disconnect()
        }
    }
}

fn process_connections(connections: &mut ConnectionState, actions: Vec<&str>) -> Vec<String> {
    let mut results = Vec::new();
    for action in actions {
        if action == "toggle" {
            results.push(connections.toggle());
        } else if action == "connect" {
            results.push(connections.connect());
        } else if action == "disconnect" {
            results.push(connections.disconnect());
        }
    }
    results
}

fn main() {
    let mut connections = ConnectionState::new();
    let actions = vec!["connect", "toggle", "disconnect", "toggle", "connect", "disconnect"];
    let results = process_connections(&mut connections, actions);
    for result in results {
        println!("{}", result);
    }
}