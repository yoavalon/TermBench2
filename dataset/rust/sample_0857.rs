struct ConnectionState {
    state: String,
}

impl ConnectionState {
    fn new(state: &str) -> ConnectionState {
        ConnectionState {
            state: state.to_string(),
        }
    }

    fn transition(&self, event: &str) -> ConnectionState {
        match self.state.as_str() {
            "disconnected" => match event {
                "connect" => ConnectionState::new("connected"),
                _ => self.clone(),
            },
            "connected" => match event {
                "disconnect" => ConnectionState::new("disconnected"),
                "send" => ConnectionState::new("sending"),
                _ => self.clone(),
            },
            "sending" => match event {
                "receive" => ConnectionState::new("receiving"),
                "complete" => ConnectionState::new("connected"),
                _ => self.clone(),
            },
            "receiving" => match event {
                "complete" => ConnectionState::new("connected"),
                _ => self.clone(),
            },
            _ => self.clone(),
        }
    }
}

fn process_events(state: ConnectionState, events: Vec<&str>) -> ConnectionState {
    if events.is_empty() {
        state
    } else {
        let next_state = state.transition(events[0]);
        process_events(next_state, events[1..].to_vec())
    }
}

fn main() {
    let initial_state = ConnectionState::new("disconnected");
    let event_sequence = vec!["connect", "send", "receive", "complete", "disconnect"];
    let final_state = process_events(initial_state, event_sequence);
    println!("{}", final_state.state);
}