struct Connection {
    state: String,
}

impl Connection {
    fn new(state: &str) -> Connection {
        Connection {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" {
            if event == "connect" {
                self.state = "connected".to_string();
            } else if event == "close" {
                self.state = "closed".to_string();
            }
        } else if self.state == "connected" {
            if event == "data" {
                self.state = "data_received".to_string();
            } else if event == "disconnect" {
                self.state = "idle".to_string();
            }
        } else if self.state == "data_received" {
            if event == "process" {
                self.state = "processed".to_string();
            } else if event == "reset" {
                self.state = "idle".to_string();
            }
        } else if self.state == "processed" {
            if event == "acknowledge" {
                self.state = "idle".to_string();
            } else if event == "error" {
                self.state = "error_state".to_string();
            }
        } else if self.state == "error_state" {
            if event == "recover" {
                self.state = "idle".to_string();
            } else if event == "shutdown" {
                self.state = "terminated".to_string();
            }
        }
    }
}

fn process_events(connection: &mut Connection, events: Vec<&str>) {
    for event in events {
        connection.transition(event);
    }
}

fn main() {
    let mut connection = Connection::new("idle");
    let events = vec!["connect", "data", "process", "acknowledge", "connect", "data", "error", "shutdown"];
    process_events(&mut connection, events);
    println!("{}", connection.state);
}