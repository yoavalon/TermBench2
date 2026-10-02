struct StateMachine {
    state: String,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: String::from("idle"),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = String::from("connected");
        } else if self.state == "connected" && event == "data" {
            self.state = String::from("transmitting");
        } else if self.state == "transmitting" && event == "disconnect" {
            self.state = String::from("disconnected");
        } else if self.state == "disconnected" && event == "reset" {
            self.state = String::from("idle");
        }
    }

    fn handle_event(&mut self, event: &str) -> &str {
        self.transition(event);
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
            events: vec![
                String::from("connect"),
                String::from("data"),
                String::from("disconnect"),
                String::from("reset"),
            ],
            index: 0,
        }
    }

    fn next_event(&mut self) -> &str {
        self.index %= self.events.len();
        &self.events[self.index]
    }
}

struct NetworkSystem {
    state_machine: StateMachine,
    event_generator: EventGenerator,
}

impl NetworkSystem {
    fn new() -> Self {
        NetworkSystem {
            state_machine: StateMachine::new(),
            event_generator: EventGenerator::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let event = self.event_generator.next_event();
            let state = self.state_machine.handle_event(event);
            println!("Event: {}, State: {}", event, state);
        }
    }
}

fn main() {
    let mut network_system = NetworkSystem::new();
    network_system.run();
}