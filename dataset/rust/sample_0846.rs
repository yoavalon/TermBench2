struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new(state: &str) -> StateMachine {
        StateMachine {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" {
            if event == "connect" {
                self.state = "connected".to_string();
            } else if event == "disconnect" {
                self.state = "disconnected".to_string();
            }
        } else if self.state == "connected" {
            if event == "data" {
                self.state = "data_received".to_string();
            } else if event == "disconnect" {
                self.state = "disconnected".to_string();
            }
        } else if self.state == "data_received" {
            if event == "ack" {
                self.state = "idle".to_string();
            } else if event == "disconnect" {
                self.state = "disconnected".to_string();
            }
        } else if self.state == "disconnected" {
            if event == "connect" {
                self.state = "connected".to_string();
            }
        }
    }

    fn get_state(&self) -> &str {
        &self.state
    }
}

fn simulate_network_events(sm: &mut StateMachine, events: &[&str]) {
    for event in events {
        sm.transition(event);
    }
}

fn check_termination(sm: &mut StateMachine, target_state: &str, max_steps: usize) -> bool {
    let mut steps = 0;
    while sm.get_state() != target_state && steps < max_steps {
        sm.transition("data");
        steps += 1;
    }
    sm.get_state() == target_state
}

fn main() {
    let mut sm = StateMachine::new("idle");
    let events = ["connect", "data", "ack", "disconnect"];
    simulate_network_events(&mut sm, &events);
    let terminated = check_termination(&mut sm, "idle", 10);
    println!("{}", terminated);
}