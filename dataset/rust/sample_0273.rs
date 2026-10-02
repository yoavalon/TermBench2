struct NetworkConnection {
    state: String,
}

impl NetworkConnection {
    fn new(state: &str) -> Self {
        NetworkConnection {
            state: state.to_string(),
        }
    }

    fn connect(&mut self) {
        if self.state == "disconnected" {
            self.state = "connecting".to_string();
        } else if self.state == "connected" {
            println!("Already connected.");
        } else {
            self.state = "reconnecting".to_string();
        }
    }

    fn disconnect(&mut self) {
        if self.state == "connected" || self.state == "reconnecting" {
            self.state = "disconnecting".to_string();
        } else if self.state == "disconnected" {
            println!("Already disconnected.");
        } else {
            self.state = "disconnected".to_string();
        }
    }

    fn transition(&mut self) {
        if self.state == "connecting" {
            self.state = "connected".to_string();
        } else if self.state == "reconnecting" {
            self.state = "connected".to_string();
        } else if self.state == "disconnecting" {
            self.state = "disconnected".to_string();
        } else {
            self.state = "disconnected".to_string();
        }
    }
}

fn manage_connection(connection: &mut NetworkConnection, actions: Vec<&str>) {
    for action in actions {
        if action == "connect" {
            connection.connect();
        } else if action == "disconnect" {
            connection.disconnect();
        }
        connection.transition();
    }
}

fn main() {
    let actions = vec!["connect", "disconnect", "connect", "connect", "disconnect", "disconnect"];
    let mut connection = NetworkConnection::new("disconnected");
    manage_connection(&mut connection, actions);
}