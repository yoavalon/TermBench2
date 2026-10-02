struct NetworkState {
    state: String,
    connection_attempts: u32,
}

impl NetworkState {
    fn new() -> NetworkState {
        NetworkState {
            state: String::from("DISCONNECTED"),
            connection_attempts: 0,
        }
    }

    fn connect(&mut self) {
        if self.state == "DISCONNECTED" {
            self.state = String::from("CONNECTING");
            self.connection_attempts += 1;
        }
    }

    fn check_status(&mut self) {
        if self.state == "CONNECTING" {
            if self.connection_attempts < 3 {
                self.state = String::from("CONNECTED");
            } else {
                self.state = String::from("FAILED");
            }
        }
    }

    fn disconnect(&mut self) {
        if self.state == "CONNECTED" {
            self.state = String::from("DISCONNECTING");
            self.connection_attempts = 0;
        }
    }
}

struct NetworkManager {
    network_state: NetworkState,
}

impl NetworkManager {
    fn new() -> NetworkManager {
        NetworkManager {
            network_state: NetworkState::new(),
        }
    }

    fn manage_connection(&mut self) {
        loop {
            self.network_state.connect();
            self.network_state.check_status();
            if self.network_state.state == "FAILED" {
                break;
            }
        }
    }
}

fn main() {
    let mut manager = NetworkManager::new();
    manager.manage_connection();
}