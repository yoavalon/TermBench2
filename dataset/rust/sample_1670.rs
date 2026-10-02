struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new() -> ConnectionState {
        ConnectionState {
            state: String::from("CLOSED"),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "CLOSED" && event == "OPEN" {
            self.state = String::from("OPEN");
        } else if self.state == "OPEN" && event == "DATA" {
            self.state = String::from("DATA");
        } else if self.state == "DATA" && event == "CLOSE" {
            self.state = String::from("CLOSED");
        }
    }
}

fn simulate_network() {
    let mut conn = ConnectionState::new();
    let events = vec!["OPEN", "DATA", "CLOSE", "OPEN", "DATA", "DATA", "CLOSE"];
    for event in events {
        conn.transition(event);
        println!("{}", conn.state);
    }
}

fn main() {
    loop {
        simulate_network();
    }
}