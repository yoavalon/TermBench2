struct NetworkStateMachine {
    state: String,
}

impl NetworkStateMachine {
    fn new(state: String) -> Self {
        NetworkStateMachine { state }
    }

    fn transition(&mut self) {
        if self.state == "CONNECTING" {
            self.state = "ESTABLISHED".to_string();
        } else if self.state == "ESTABLISHED" {
            self.state = "DISCONNECTING".to_string();
        } else if self.state == "DISCONNECTING" {
            self.state = "CONNECTING".to_string();
        }
    }
}

fn recursive_process(state_machine: &mut NetworkStateMachine) {
    println!("{}", state_machine.state);
    state_machine.transition();
    recursive_process(state_machine);
}

fn main() {
    let initial_state = "CONNECTING".to_string();
    let mut state_machine = NetworkStateMachine::new(initial_state);
    recursive_process(&mut state_machine);
}