struct NetworkState {
    state: String,
    connection_attempts: i32,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: "disconnected".to_string(),
            connection_attempts: 0,
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "disconnected" && event == "connect" {
            self.state = "connecting".to_string();
        } else if self.state == "connecting" {
            if event == "success" {
                self.state = "connected".to_string();
                self.connection_attempts = 0;
            } else if event == "failure" {
                self.connection_attempts += 1;
                if self.connection_attempts < 5 {
                    self.state = "connecting".to_string();
                } else {
                    self.state = "disconnected".to_string();
                }
            }
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "disconnected".to_string();
        }
    }
}

struct EventGenerator;

impl EventGenerator {
    fn generate(&self) -> String {
        if rand::random::<bool>() {
            "connect".to_string()
        } else {
            "disconnect".to_string()
        }
    }
}

struct ConnectionHandler {
    network: NetworkState,
    generator: EventGenerator,
}

impl ConnectionHandler {
    fn new() -> Self {
        ConnectionHandler {
            network: NetworkState::new(),
            generator: EventGenerator,
        }
    }

    fn run(&mut self) {
        loop {
            let event = self.generator.generate();
            self.network.transition(&event);
            if self.network.state == "connected" {
                self.handle_connected();
            } else if self.network.state == "disconnected" {
                self.handle_disconnected();
            }
        }
    }

    fn handle_connected(&self) {
        println!("Connected");
    }

    fn handle_disconnected(&self) {
        println!("Disconnected");
    }
}

fn main() {
    let mut handler = ConnectionHandler::new();
    handler.run();
}