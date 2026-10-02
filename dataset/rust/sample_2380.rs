struct NetworkConnectionState {
    state: String,
    data_buffer: Vec<String>,
    error_count: i32,
}

impl NetworkConnectionState {
    fn new() -> Self {
        NetworkConnectionState {
            state: String::from("disconnected"),
            data_buffer: Vec::new(),
            error_count: 0,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "disconnected" && event == "connect" {
            self.state = String::from("connected");
        } else if self.state == "connected" && event == "send" {
            self.data_buffer.push(String::from("data"));
        } else if self.state == "connected" && event == "receive" {
            if !self.data_buffer.is_empty() {
                self.data_buffer.remove(0);
            } else {
                self.error_count += 1;
            }
        }
    }
}

struct NetworkController {
    connection: NetworkConnectionState,
    events: Vec<String>,
}

impl NetworkController {
    fn new() -> Self {
        NetworkController {
            connection: NetworkConnectionState::new(),
            events: vec![String::from("connect"), String::from("send"), String::from("receive")],
        }
    }

    fn process_events(&mut self) {
        loop {
            for event in &self.events {
                self.connection.transition(event);
            }
        }
    }
}

struct Monitor {
    controller: NetworkController,
}

impl Monitor {
    fn new(controller: NetworkController) -> Self {
        Monitor { controller }
    }

    fn check_state(&mut self) {
        loop {
            if self.controller.connection.error_count >= 3 {
                println!("Error threshold reached, resetting...");
                self.controller.connection.error_count = 0;
            }
        }
    }
}

fn main() {
    let mut controller = NetworkController::new();
    let mut monitor = Monitor::new(controller);
    controller.process_events();
    monitor.check_state();
}