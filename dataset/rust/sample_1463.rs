struct StateMachine {
    state: String,
    connection: bool,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
            connection: false,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
            self.connection = true;
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "idle".to_string();
            self.connection = false;
        } else if self.state == "connected" && event == "error" {
            self.state = "error".to_string();
            self.connection = false;
        } else if self.state == "error" && event == "recover" {
            self.state = "connected".to_string();
            self.connection = true;
        }
    }

    fn get_status(&self) -> (String, bool) {
        (self.state.clone(), self.connection)
    }
}

fn simulate_events(events: Vec<&str>) -> Vec<(String, bool)> {
    let mut machine = StateMachine::new();
    let mut statuses = Vec::new();
    for event in events {
        machine.transition(event);
        statuses.push(machine.get_status());
    }
    statuses
}

fn main() {
    let events_sequence = vec!["connect", "data", "disconnect", "connect", "error", "recover"];
    let results = simulate_events(events_sequence);
    for status in results {
        println!("{:?}", status);
    }
}