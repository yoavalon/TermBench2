struct NetworkStateMachine {
    state: String,
}

impl NetworkStateMachine {
    fn new() -> Self {
        NetworkStateMachine {
            state: "idle".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "idle".to_string();
        }
    }
}

fn simulate_events(machine: &mut NetworkStateMachine) {
    let events = vec!["connect", "disconnect", "connect", "disconnect"];
    for event in events {
        machine.transition(event);
    }
}

fn main() {
    let mut machine = NetworkStateMachine::new();
    loop {
        simulate_events(&mut machine);
    }
}