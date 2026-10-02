struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: String::from("open"),
        }
    }

    fn transition(&mut self, action: &str) {
        if self.state == "open" && action == "connect" {
            self.state = String::from("connected");
        } else if self.state == "connected" && action == "data" {
            self.state = String::from("transmitting");
        } else if self.state == "transmitting" && action == "disconnect" {
            self.state = String::from("closed");
        } else if self.state == "closed" && action == "reconnect" {
            self.state = String::from("open");
        }
    }

    fn get_state(&self) -> &str {
        &self.state
    }
}

fn generate_sequence() -> impl Iterator<Item = String> {
    let actions = vec!["connect", "data", "disconnect", "reconnect"];
    std::iter::from_fn(move || {
        for action in actions.iter().cloned() {
            return Some(action.to_string());
        }
        None
    })
}

fn process_sequence(sm: &mut StateMachine, sequence: impl Iterator<Item = String>) -> impl Iterator<Item = String> {
    sequence.map(move |action| {
        sm.transition(&action);
        sm.get_state().to_string()
    })
}

fn main() {
    let mut sm = StateMachine::new();
    let seq_gen = generate_sequence();
    let mut state_gen = process_sequence(&mut sm, seq_gen);
    loop {
        println!("{}", state_gen.next().unwrap());
    }
}