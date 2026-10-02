struct NetworkState {
    status: String,
    connection_attempts: i32,
}

impl NetworkState {
    fn new() -> NetworkState {
        NetworkState {
            status: String::from("disconnected"),
            connection_attempts: 0,
        }
    }

    fn connect(&mut self) {
        self.connection_attempts += 1;
        if self.connection_attempts < 5 {
            self.status = String::from("connecting");
            self.transition();
        } else {
            self.status = String::from("failed");
        }
    }

    fn transition(&mut self) {
        if self.status == "connecting" {
            self.status = String::from("connected");
        } else if self.status == "connected" {
            self.status = String::from("disconnecting");
        } else if self.status == "disconnecting" {
            self.status = String::from("disconnected");
            self.connection_attempts = 0;
        }
    }

    fn check_status(&self) -> &str {
        &self.status
    }
}

fn state_manager(state: &mut NetworkState) {
    loop {
        if state.check_status() == "disconnected" {
            state.connect();
        } else if state.check_status() == "connecting" {
            state.transition();
        } else if state.check_status() == "connected" {
            state.transition();
        } else if state.check_status() == "disconnecting" {
            state.transition();
        } else if state.check_status() == "failed" {
            break;
        }
    }
}

fn main() {
    let mut network_state = NetworkState::new();
    state_manager(&mut network_state);
}