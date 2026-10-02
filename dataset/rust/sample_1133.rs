struct NetworkConnection {
    state: String,
}

impl NetworkConnection {
    fn new(state: &str) -> Self {
        NetworkConnection {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "closed" {
            if event == "open" {
                self.state = "open".to_string();
                self.transition(event);
            } else if event == "listen" {
                self.state = "listening".to_string();
                self.transition(event);
            }
        } else if self.state == "open" {
            if event == "close" {
                self.state = "closed".to_string();
                self.transition(event);
            } else if event == "send" {
                self.state = "sending".to_string();
                self.transition(event);
            }
        } else if self.state == "listening" {
            if event == "accept" {
                self.state = "open".to_string();
                self.transition(event);
            }
        } else if self.state == "sending" {
            if event == "complete" {
                self.state = "open".to_string();
                self.transition(event);
            }
        }
    }
}

fn event_generator() -> std::iter::Cycle<std::vec::IntoIter<&'static str>> {
    let events = vec!["open", "listen", "accept", "send", "complete", "close"];
    events.into_iter().cycle()
}

fn main() {
    let mut connection = NetworkConnection::new("closed");
    for event in event_generator() {
        connection.transition(event);
    }
}