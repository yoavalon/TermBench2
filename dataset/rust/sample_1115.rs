struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new(state: &str) -> StateMachine {
        StateMachine {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "open" {
            if event == "data" {
                self.state = "data_received".to_string();
            } else if event == "close" {
                self.state = "closed".to_string();
            }
        } else if self.state == "data_received" {
            if event == "ack" {
                self.state = "acknowledged".to_string();
            } else if event == "error" {
                self.state = "error".to_string();
            }
        } else if self.state == "acknowledged" {
            if event == "data" {
                self.state = "data_received".to_string();
            } else if event == "close" {
                self.state = "closed".to_string();
            }
        } else if self.state == "error" {
            if event == "reset" {
                self.state = "open".to_string();
            } else if event == "close" {
                self.state = "closed".to_string();
            }
        }
    }
}

fn event_generator() -> impl Iterator<Item = String> {
    let events = vec![
        "data".to_string(),
        "data".to_string(),
        "ack".to_string(),
        "data".to_string(),
        "error".to_string(),
        "reset".to_string(),
        "data".to_string(),
        "close".to_string(),
    ];
    std::iter::from_fn(move || Some(events.clone().into_iter().next().unwrap()))
}

fn simulate_network_connection() {
    let mut state_machine = StateMachine::new("open");
    let mut event_stream = event_generator();
    loop {
        if let Some(event) = event_stream.next() {
            state_machine.transition(&event);
            println!("Event: {}, State: {}", event, state_machine.state);
        }
    }
}

fn main() {
    simulate_network_connection();
}