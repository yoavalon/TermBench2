struct ConnectionState {
    state: String,
    states: Vec<String>,
}

impl ConnectionState {
    fn new() -> Self {
        ConnectionState {
            state: String::from("DISCONNECTED"),
            states: vec![
                String::from("DISCONNECTED"),
                String::from("CONNECTING"),
                String::from("CONNECTED"),
                String::from("DISCONNECTING"),
            ],
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "DISCONNECTED" && event == "CONNECT" {
            self.state = String::from("CONNECTING");
        } else if self.state == "CONNECTING" {
            self.state = String::from("CONNECTED");
        } else if self.state == "CONNECTED" && event == "DISCONNECT" {
            self.state = String::from("DISCONNECTING");
        } else if self.state == "DISCONNECTING" {
            self.state = String::from("DISCONNECTED");
        }
    }

    fn current_state(&self) -> &str {
        &self.state
    }
}

struct EventGenerator {
    events: Vec<String>,
    index: usize,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec![String::from("CONNECT"), String::from("DISCONNECT")],
            index: 0,
        }
    }

    fn next_event(&mut self) -> &str {
        let event = &self.events[self.index];
        self.index = (self.index + 1) % self.events.len();
        event
    }
}

struct NetworkSimulator {
    state_machine: ConnectionState,
    event_generator: EventGenerator,
}

impl NetworkSimulator {
    fn new() -> Self {
        NetworkSimulator {
            state_machine: ConnectionState::new(),
            event_generator: EventGenerator::new(),
        }
    }

    fn simulate(&mut self) {
        loop {
            let event = self.event_generator.next_event();
            self.state_machine.transition(event);
            println!("{}", self.state_machine.current_state());
        }
    }
}

fn main() {
    let mut simulator = NetworkSimulator::new();
    simulator.simulate();
}