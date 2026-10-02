struct NetworkState {
    state: String,
    connection: Option<bool>,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: "idle".to_string(),
            connection: None,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected".to_string();
            self.connection = Some(true);
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "idle".to_string();
            self.connection = Some(false);
        } else if self.state == "idle" && event == "error" {
            self.state = "error".to_string();
        } else if self.state == "connected" && event == "error" {
            self.state = "error".to_string();
        } else if self.state == "error" && event == "recover" {
            self.state = "idle".to_string();
        }
    }
}

struct EventGenerator {
    events: Vec<&'static str>,
    index: usize,
}

impl EventGenerator {
    fn new() -> Self {
        EventGenerator {
            events: vec!["connect", "disconnect", "error", "recover"],
            index: 0,
        }
    }

    fn next_event(&mut self) -> &str {
        let event = self.events[self.index];
        self.index = (self.index + 1) % self.events.len();
        event
    }
}

struct NetworkSystem {
    state_machine: NetworkState,
    event_source: EventGenerator,
}

impl NetworkSystem {
    fn new() -> Self {
        NetworkSystem {
            state_machine: NetworkState::new(),
            event_source: EventGenerator::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let event = self.event_source.next_event();
            self.state_machine.transition(event);
            println!("Event: {}, State: {}", event, self.state_machine.state);
        }
    }
}

fn main() {
    let mut system = NetworkSystem::new();
    system.run();
}