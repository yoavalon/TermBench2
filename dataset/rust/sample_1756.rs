use rand::Rng;

struct NetworkConnection {
    state: String,
}

impl NetworkConnection {
    fn new(state: &str) -> Self {
        NetworkConnection {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "disconnected" && event == "connect" {
            self.state = "connected".to_string();
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "disconnected".to_string();
        } else if self.state == "connected" && event == "error" {
            self.state = "error".to_string();
        } else if self.state == "error" && event == "recover" {
            self.state = "connected".to_string();
        }
    }
}

struct EventGenerator;

impl EventGenerator {
    fn generate(&self) -> String {
        let events = vec!["connect", "disconnect", "error", "recover"];
        let mut rng = rand::thread_rng();
        events[rng.gen_range(0..events.len())].to_string()
    }
}

struct StateSimulator {
    connection: NetworkConnection,
    generator: EventGenerator,
}

impl StateSimulator {
    fn new() -> Self {
        StateSimulator {
            connection: NetworkConnection::new("disconnected"),
            generator: EventGenerator,
        }
    }

    fn simulate(&mut self) {
        loop {
            let event = self.generator.generate();
            self.connection.transition(&event);
            println!("Event: {}, State: {}", event, self.connection.state);
        }
    }
}

fn main() {
    let mut simulator = StateSimulator::new();
    simulator.simulate();
}