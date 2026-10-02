struct StateMachine {
    state: String,
    states: std::collections::HashMap<String, fn(&StateMachine, &str) -> String>,
}

impl StateMachine {
    fn new() -> StateMachine {
        let mut states = std::collections::HashMap::new();
        states.insert("idle".to_string(), StateMachine::idle);
        states.insert("connected".to_string(), StateMachine::connected);
        states.insert("error".to_string(), StateMachine::error);
        StateMachine {
            state: "idle".to_string(),
            states,
        }
    }

    fn transition(&mut self, event: &str) {
        self.state = (self.states[&self.state])(self, event);
    }

    fn idle(&self, event: &str) -> String {
        if event == "connect" {
            "connected".to_string()
        } else if event == "error" {
            "error".to_string()
        } else {
            "idle".to_string()
        }
    }

    fn connected(&self, event: &str) -> String {
        if event == "disconnect" {
            "idle".to_string()
        } else if event == "error" {
            "error".to_string()
        } else {
            "connected".to_string()
        }
    }

    fn error(&self, event: &str) -> String {
        if event == "recover" {
            "idle".to_string()
        } else {
            "error".to_string()
        }
    }
}

fn simulate_events(machine: &mut StateMachine) {
    let events = vec!["connect", "data", "disconnect", "connect", "error", "recover"];
    for event in events {
        machine.transition(event);
    }
}

fn main() {
    let mut machine = StateMachine::new();
    simulate_events(&mut machine);
}