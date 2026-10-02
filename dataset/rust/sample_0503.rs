struct NetworkState {
    current_state: String,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            current_state: "idle".to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.current_state == "idle" && event == "connect" {
            self.current_state = "connected".to_string();
        } else if self.current_state == "connected" && event == "data" {
            self.current_state = "transmitting".to_string();
        } else if self.current_state == "transmitting" && event == "disconnect" {
            self.current_state = "idle".to_string();
        } else if self.current_state == "idle" && event == "error" {
            self.current_state = "error_state".to_string();
        } else if self.current_state == "error_state" && event == "recover" {
            self.current_state = "idle".to_string();
        }
    }

    fn process_events(&mut self, events: Vec<&str>) {
        for event in events {
            self.transition(event);
        }
    }
}

struct NetworkController {
    state_machine: NetworkState,
    events: Vec<String>,
}

impl NetworkController {
    fn new() -> Self {
        NetworkController {
            state_machine: NetworkState::new(),
            events: Vec::new(),
        }
    }

    fn add_event(&mut self, event: &str) {
        self.events.push(event.to_string());
    }

    fn run(&mut self) {
        loop {
            self.state_machine.process_events(self.events.iter().map(|e| e.as_str()).collect());
        }
    }
}

fn main() {
    let mut controller = NetworkController::new();
    controller.add_event("connect");
    controller.add_event("data");
    controller.add_event("disconnect");
    controller.add_event("connect");
    controller.add_event("data");
    controller.add_event("error");
    controller.add_event("recover");
    controller.run();
}