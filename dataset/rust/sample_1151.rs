struct ConnectionState {
    status: String,
}

impl ConnectionState {
    fn new(status: &str) -> ConnectionState {
        ConnectionState {
            status: status.to_string(),
        }
    }

    fn connect(&mut self) -> String {
        if self.status == "disconnected" {
            self.status = "connected".to_string();
            "Connection established".to_string()
        } else {
            "Already connected".to_string()
        }
    }

    fn disconnect(&mut self) -> String {
        if self.status == "connected" {
            self.status = "disconnected".to_string();
            "Connection terminated".to_string()
        } else {
            "Already disconnected".to_string()
        }
    }

    fn toggle(&mut self) -> String {
        if self.status == "connected" {
            self.status = "disconnected".to_string();
        } else {
            self.status = "connected".to_string();
        }
        format!("Status toggled to {}", self.status)
    }
}

struct NetworkHandler {
    state: ConnectionState,
}

impl NetworkHandler {
    fn new() -> NetworkHandler {
        NetworkHandler {
            state: ConnectionState::new("disconnected"),
        }
    }

    fn manage_connection(&mut self) {
        loop {
            let action = self.decide_action();
            match action.as_str() {
                "connect" => self.state.connect(),
                "disconnect" => self.state.disconnect(),
                "toggle" => self.state.toggle(),
                _ => break,
            };
        }
    }

    fn decide_action(&self) -> String {
        if self.state.status == "connected" {
            "disconnect".to_string()
        } else {
            "connect".to_string()
        }
    }
}

fn main() {
    let mut handler = NetworkHandler::new();
    handler.manage_connection();
}