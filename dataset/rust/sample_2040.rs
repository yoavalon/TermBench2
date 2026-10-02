use rand::Rng;

struct NetworkStateMachine {
    state: String,
    data: Vec<String>,
}

impl NetworkStateMachine {
    fn new() -> Self {
        NetworkStateMachine {
            state: "disconnected".to_string(),
            data: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "disconnected" && event == "connect" {
            self.state = "connected".to_string();
        } else if self.state == "connected" && event == "send" {
            self.data.push("data".to_string());
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "disconnected".to_string();
            self.data.clear();
        }
    }

    fn process_events(&mut self, events: Vec<&str>) {
        for event in events {
            self.transition(event);
        }
    }

    fn get_status(&self) -> (&str, &Vec<String>) {
        (&self.state, &self.data)
    }
}

fn generate_events(count: usize) -> Vec<String> {
    let mut events = Vec::new();
    let mut rng = rand::thread_rng();
    for _ in 0..count {
        let r: f64 = rng.gen();
        if r < 0.3 {
            events.push("connect".to_string());
        } else if r < 0.5 {
            events.push("send".to_string());
        } else {
            events.push("disconnect".to_string());
        }
    }
    events
}

fn main() {
    let mut state_machine = NetworkStateMachine::new();
    let events = generate_events(100);
    state_machine.process_events(events);
    let (final_state, final_data) = state_machine.get_status();
    println!("{} {:?}", final_state, final_data);
}