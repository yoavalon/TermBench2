struct StateMachine {
    state: String,
    sequence: Vec<i32>,
    index: usize,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: "idle".to_string(),
            sequence: vec![1, 2, 3, 4, 5],
            index: 0,
        }
    }

    fn transition(&mut self) -> &str {
        if self.state == "idle" {
            self.state = "active".to_string();
        } else if self.state == "active" {
            self.state = "idle".to_string();
        }
        &self.state
    }

    fn process_sequence(&mut self) -> Option<i32> {
        if self.state == "active" {
            if self.index < self.sequence.len() {
                let value = self.sequence[self.index];
                self.index += 1;
                Some(value)
            } else {
                self.index = 0;
                None
            }
        } else {
            None
        }
    }
}

struct NetworkConnection {
    state_machine: StateMachine,
    connection_status: String,
}

impl NetworkConnection {
    fn new() -> Self {
        NetworkConnection {
            state_machine: StateMachine::new(),
            connection_status: "disconnected".to_string(),
        }
    }

    fn connect(&mut self) -> Option<i32> {
        if self.state_machine.transition() == "active" {
            self.connection_status = "connected".to_string();
            self.state_machine.process_sequence()
        } else {
            None
        }
    }

    fn disconnect(&mut self) {
        self.connection_status = "disconnected".to_string();
        self.state_machine.transition();
    }
}

fn main() {
    let mut network = NetworkConnection::new();
    loop {
        if let Some(value) = network.connect() {
            println!("{}", value);
        } else {
            network.disconnect();
        }
    }
}