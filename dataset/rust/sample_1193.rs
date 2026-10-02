struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" {
            if event == "connect" {
                self.state = "active".to_string();
            } else if event == "error" {
                self.state = "errored".to_string();
            }
        } else if self.state == "active" {
            if event == "disconnect" {
                self.state = "idle".to_string();
            } else if event == "error" {
                self.state = "errored".to_string();
            }
        } else if self.state == "errored" {
            if event == "recover" {
                self.state = "idle".to_string();
            }
        }
    }

    fn process(&mut self, event_sequence: Vec<&str>) -> Vec<String> {
        let mut states = Vec::new();
        for event in event_sequence {
            self.transition(event);
            states.push(self.state.clone());
        }
        states
    }
}

fn generate_events() -> impl Iterator<Item = &'static str> {
    std::iter::repeat_with(|| {
        static EVENTS: [&str; 4] = ["connect", "disconnect", "error", "recover"];
        static mut INDEX: usize = 0;
        let event = EVENTS[unsafe { INDEX }];
        unsafe {
            INDEX = (INDEX + 1) % EVENTS.len();
        }
        event
    })
}

fn monitor(state_machine: &mut StateMachine, event_generator: impl Iterator<Item = &'static str>) {
    for event in event_generator {
        state_machine.transition(event);
        println!("Event: {}, State: {}", event, state_machine.state);
    }
}

fn main() {
    let mut state_machine = StateMachine::new();
    let event_generator = generate_events();
    monitor(&mut state_machine, event_generator);
}