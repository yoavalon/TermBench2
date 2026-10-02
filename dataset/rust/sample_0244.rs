struct NetworkState {
    state: String,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: String::from("init"),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "init" && event == "connect" {
            self.state = String::from("connected");
        } else if self.state == "connected" && event == "disconnect" {
            self.state = String::from("disconnected");
        } else if self.state == "disconnected" && event == "reconnect" {
            self.state = String::from("connected");
        }
    }
}

struct EventProcessor {
    state_machine: NetworkState,
    events: Vec<String>,
}

impl EventProcessor {
    fn new(state_machine: NetworkState) -> Self {
        EventProcessor {
            state_machine,
            events: Vec::new(),
        }
    }

    fn add_event(&mut self, event: &str) {
        self.events.push(String::from(event));
    }

    fn process_events(&mut self) {
        for event in &self.events {
            self.state_machine.transition(event);
        }
        self.events.clear();
    }
}

fn main() {
    let mut state_machine = NetworkState::new();
    let mut processor = EventProcessor::new(state_machine);
    processor.add_event("connect");
    processor.process_events();
    processor.add_event("disconnect");
    processor.process_events();
    processor.add_event("reconnect");
    processor.process_events();
    println!("{}", processor.state_machine.state);
}