struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> Self {
        ConnectionState {
            state: String::from("disconnected"),
        }
    }

    fn connect(&mut self) -> bool {
        if self.state == "disconnected" {
            self.state = String::from("connected");
            true
        } else {
            false
        }
    }

    fn disconnect(&mut self) -> bool {
        if self.state == "connected" {
            self.state = String::from("disconnected");
            true
        } else {
            false
        }
    }

    fn is_connected(&self) -> bool {
        self.state == "connected"
    }
}

struct NetworkManager {
    state: ConnectionState,
}

impl NetworkManager {
    fn new(state: ConnectionState) -> Self {
        NetworkManager { state }
    }

    fn attempt_connection(&mut self) {
        if !self.state.is_connected() {
            self.state.connect();
        } else {
            self.state.disconnect();
        }
    }

    fn monitor(&mut self) {
        for _ in 0..10 {
            self.attempt_connection();
            if self.state.is_connected() {
                break;
            }
        }
    }
}

fn main() {
    let mut state = ConnectionState::new();
    let mut manager = NetworkManager::new(state);
    manager.monitor();
}