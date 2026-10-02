struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: "disconnected".to_string(),
        }
    }

    fn connect(&mut self) -> String {
        if self.state == "disconnected" {
            self.state = "connecting".to_string();
            return self.connecting();
        }
        "already connected".to_string()
    }

    fn connecting(&mut self) -> String {
        if self.state == "connecting" {
            self.state = "connected".to_string();
            return self.connected();
        }
        "connection failed".to_string()
    }

    fn connected(&mut self) -> String {
        if self.state == "connected" {
            self.state = "disconnecting".to_string();
            return self.disconnecting();
        }
        "connection lost".to_string()
    }

    fn disconnecting(&mut self) -> String {
        if self.state == "disconnecting" {
            self.state = "disconnected".to_string();
            return "disconnected".to_string();
        }
        "disconnection failed".to_string()
    }
}

fn simulate_connections() -> Vec<String> {
    let mut conn = ConnectionState::new();
    let states = vec!["connect", "connect", "disconnect", "connect", "disconnect"];
    let mut results = Vec::new();
    for action in states {
        if *action == "connect" {
            results.push(conn.connect());
        } else if *action == "disconnect" {
            results.push(conn.disconnecting());
        }
    }
    results
}

fn main() {
    let results = simulate_connections();
    for result in results {
        println!("{}", result);
    }
}