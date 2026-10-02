struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "initial".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        match self.state.as_str() {
            "initial" => {
                if event == "connect" {
                    self.state = "connected".to_string();
                } else {
                    self.state = "error".to_string();
                }
            }
            "connected" => {
                if event == "disconnect" {
                    self.state = "disconnected".to_string();
                } else if event == "data" {
                    self.state = "processing".to_string();
                } else {
                    self.state = "error".to_string();
                }
            }
            "processing" => {
                if event == "complete" {
                    self.state = "connected".to_string();
                } else {
                    self.state = "error".to_string();
                }
            }
            "disconnected" => {
                if event == "connect" {
                    self.state = "connected".to_string();
                } else {
                    self.state = "error".to_string();
                }
            }
            "error" => {
                if event == "reset" {
                    self.state = "initial".to_string();
                } else {
                    self.state = "error".to_string();
                }
            }
            _ => {}
        }
    }
}

fn event_generator() -> impl Iterator<Item = String> {
    let events = vec![
        "connect".to_string(),
        "disconnect".to_string(),
        "data".to_string(),
        "complete".to_string(),
        "reset".to_string(),
    ];
    std::iter::repeat_with(|| events[fastrand::usize(0..events.len())].clone())
}

fn process_events(state_machine: &mut StateMachine) {
    let mut generator = event_generator();
    loop {
        let event = generator.next().unwrap();
        state_machine.transition(&event);
    }
}

fn main() {
    let mut state_machine = StateMachine::new();
    process_events(&mut state_machine);
}