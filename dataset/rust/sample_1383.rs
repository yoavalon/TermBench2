struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
        }
    }

    fn transition(&mut self, event: &str) -> &str {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "idle".to_string();
        } else if self.state == "idle" && event == "error" {
            self.state = "error".to_string();
        } else if self.state == "error" && event == "recover" {
            self.state = "idle".to_string();
        }
        &self.state
    }
}

fn process_events(events: Vec<&str>) -> String {
    let mut machine = StateMachine::new();
    for event in events {
        machine.transition(event);
    }
    machine.state
}

fn main() {
    let events = vec!["connect", "disconnect", "connect", "error", "recover"];
    let final_state = process_events(events);
    println!("{}", final_state);
}