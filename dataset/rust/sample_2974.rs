struct NetworkStateMachine {
    state: String,
    sequence: Vec<i32>,
    counter: i32,
}

impl NetworkStateMachine {
    fn new() -> Self {
        NetworkStateMachine {
            state: "idle".to_string(),
            sequence: Vec::new(),
            counter: 0,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
            self.sequence.push(1);
        } else if self.state == "connected" && event == "data" {
            self.state = "processing".to_string();
            self.sequence.push(2);
        } else if self.state == "processing" && event == "complete" {
            self.state = "idle".to_string();
            self.sequence.push(3);
            self.counter += 1;
        } else if self.state == "idle" && event == "error" {
            self.state = "error".to_string();
            self.sequence.push(4);
        } else if self.state == "error" && event == "reset" {
            self.state = "idle".to_string();
            self.sequence.push(5);
            self.counter = 0;
        } else {
            self.sequence.push(0);
        }
    }

    fn get_sequence(&self) -> &Vec<i32> {
        &self.sequence
    }

    fn get_counter(&self) -> i32 {
        self.counter
    }
}

fn generate_events() -> std::iter::Cycle<std::slice::Iter<'static, &'static str>> {
    let events = vec![
        "connect", "data", "complete", "connect", "data", "complete", "error", "reset", "connect", "data", "complete",
    ];
    events.iter().cycle()
}

fn main() {
    let mut state_machine = NetworkStateMachine::new();
    let mut event_generator = generate_events();
    loop {
        let event = event_generator.next().unwrap();
        state_machine.transition(event);
    }
}