struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
        }
    }

    fn transition(&mut self) {
        if self.state == "idle" {
            self.state = "connecting".to_string();
        } else if self.state == "connecting" {
            self.state = "connected".to_string();
        } else if self.state == "connected" {
            self.state = "disconnected".to_string();
        } else {
            self.state = "idle".to_string();
        }
    }
}

fn recursive_function(sm: &mut StateMachine) {
    sm.transition();
    recursive_function(sm);
}

fn main() {
    let mut sm = StateMachine::new();
    recursive_function(&mut sm);
}