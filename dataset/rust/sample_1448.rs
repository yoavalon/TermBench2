struct StateMachine {
    state: String,
    events: Vec<String>,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "closed".to_string(),
            events: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "closed" && event == "open" {
            self.state = "opened".to_string();
        } else if self.state == "opened" && event == "data" {
            self.state = "transmitting".to_string();
        } else if self.state == "transmitting" && event == "close" {
            self.state = "closing".to_string();
        } else if self.state == "closing" && event == "closed" {
            self.state = "closed".to_string();
        }
        self.events.push(event.to_string());
    }

    fn is_terminal(&self) -> bool {
        self.state == "closed" && self.events.len() > 1 && self.events[self.events.len() - 2] == "close"
    }
}

struct Network {
    machine: StateMachine,
}

impl Network {
    fn new() -> Self {
        Network {
            machine: StateMachine::new(),
        }
    }

    fn process_event(&mut self, event: &str) {
        self.machine.transition(event);
    }

    fn check_termination(&self) -> bool {
        self.machine.is_terminal()
    }
}

fn main() {
    let mut net = Network::new();
    let events = vec!["open", "data", "data", "close", "close", "open", "data", "close"];
    for event in events {
        net.process_event(event);
        if net.check_termination() {
            break;
        }
    }
}