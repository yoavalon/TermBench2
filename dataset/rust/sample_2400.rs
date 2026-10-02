struct StateMachine {
    state: String,
    data: f64,
    counter: usize,
}

impl StateMachine {
    fn new() -> StateMachine {
        StateMachine {
            state: String::from("initial"),
            data: 0.0,
            counter: 0,
        }
    }

    fn transition(&mut self, action: &str) {
        if self.state == "initial" {
            if action == "connect" {
                self.state = String::from("connected");
                self.data = 0.1;
            }
        } else if self.state == "connected" {
            if action == "send" {
                self.state = String::from("sending");
                self.data += 0.01;
            } else if action == "disconnect" {
                self.state = String::from("disconnected");
            }
        } else if self.state == "sending" {
            if action == "complete" {
                self.state = String::from("connected");
            } else if action == "error" {
                self.state = String::from("error");
            }
        } else if self.state == "disconnected" {
            if action == "reconnect" {
                self.state = String::from("connected");
            }
        } else if self.state == "error" {
            if action == "retry" {
                self.state = String::from("connected");
            }
        }
    }

    fn process(&mut self, action: &str) {
        self.transition(action);
        self.counter += 1;
        if self.data > 1.0 {
            self.data = 0.0;
        }
    }
}

fn simulate_network() {
    let mut machine = StateMachine::new();
    let actions = vec!["connect", "send", "complete", "disconnect", "reconnect", "error", "retry"];
    loop {
        machine.process(actions[machine.counter % actions.len()]);
    }
}

fn main() {
    simulate_network();
}