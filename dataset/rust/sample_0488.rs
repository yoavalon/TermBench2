struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: String::from("closed"),
        }
    }

    fn transition(&mut self, event: &str) -> &str {
        if self.state == "closed" && event == "connect" {
            self.state = String::from("open");
        } else if self.state == "open" && event == "disconnect" {
            self.state = String::from("closed");
        }
        &self.state
    }
}

fn simulate_network() {
    let mut machine = StateMachine::new();
    loop {
        let event = if machine.state == "closed" { "connect" } else { "disconnect" };
        let new_state = machine.transition(event);
        println!("Event: {}, New State: {}", event, new_state);
    }
}

fn main() {
    simulate_network();
}