struct NetworkState {
    state: String,
}

impl NetworkState {
    fn new(state: &str) -> NetworkState {
        NetworkState {
            state: state.to_string(),
        }
    }

    fn transition(&self, event: &str) -> String {
        match self.state.as_str() {
            "initial" => match event {
                "connect" => "connected".to_string(),
                "timeout" => "failed".to_string(),
                _ => self.state.clone(),
            },
            "connected" => match event {
                "disconnect" => "disconnected".to_string(),
                "data" => "data_received".to_string(),
                _ => self.state.clone(),
            },
            "disconnected" => match event {
                "reconnect" => "reconnecting".to_string(),
                _ => self.state.clone(),
            },
            "failed" => match event {
                "retry" => "reconnecting".to_string(),
                _ => self.state.clone(),
            },
            "reconnecting" => match event {
                "connect" => "connected".to_string(),
                "timeout" => "failed".to_string(),
                _ => self.state.clone(),
            },
            "data_received" => match event {
                "process" => "processing".to_string(),
                "disconnect" => "disconnected".to_string(),
                _ => self.state.clone(),
            },
            "processing" => match event {
                "complete" => "processed".to_string(),
                "error" => "failed".to_string(),
                _ => self.state.clone(),
            },
            "processed" => match event {
                "end" => "final".to_string(),
                _ => self.state.clone(),
            },
            _ => self.state.clone(),
        }
    }
}

fn process_event(state: &NetworkState, event: &str) -> NetworkState {
    NetworkState::new(&state.transition(event))
}

fn simulate_network() {
    let states = vec![
        "initial", "connected", "disconnected", "failed", "reconnecting", "data_received", 
        "processing", "processed", "final"
    ];
    let events = vec![
        "connect", "disconnect", "data", "process", "complete", "error", "retry", "timeout", "end"
    ];
    let mut current_state = NetworkState::new("initial");
    for _ in 0..10 {
        let event = events[_ % events.len()];
        current_state = process_event(&current_state, event);
        if current_state.state == "final" {
            break;
        }
    }
}

fn main() {
    simulate_network();
}