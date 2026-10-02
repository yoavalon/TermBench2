struct ConnectionState {
    state: String,
    data: f64,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: "DISCONNECTED".to_string(),
            data: 0.0,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "DISCONNECTED" {
            if event == "CONNECT" {
                self.state = "CONNECTED".to_string();
                self.data = 1.0;
            }
        } else if self.state == "CONNECTED" {
            if event == "TRANSMIT" {
                self.data += 0.1;
                if self.data >= 2.0 {
                    self.state = "DISCONNECTED".to_string();
                    self.data = 0.0;
                }
            } else if event == "DISCONNECT" {
                self.state = "DISCONNECTED".to_string();
                self.data = 0.0;
            }
        }
    }

    fn get_state(&self) -> &str {
        &self.state
    }
}

fn simulate_network() {
    let states = vec!["CONNECT", "TRANSMIT", "DISCONNECT"];
    let mut conn = ConnectionState::new();
    for _ in 0..10 {
        let event = states[_ % 3];
        conn.transition(event);
        if conn.get_state() == "DISCONNECTED" {
            break;
        }
    }
}

fn main() {
    simulate_network();
}