struct Connection {
    state: String,
}

impl Connection {
    fn new(state: &str) -> Connection {
        Connection {
            state: state.to_string(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "closed" {
            if event == "open" {
                self.state = "open".to_string();
            }
        } else if self.state == "open" {
            if event == "data" {
                self.state = "processing".to_string();
            } else if event == "close" {
                self.state = "closing".to_string();
            }
        } else if self.state == "processing" {
            if event == "complete" {
                self.state = "open".to_string();
            }
        } else if self.state == "closing" {
            if event == "closed" {
                self.state = "closed".to_string();
            }
        }
    }

    fn is_active(&self) -> bool {
        matches!(self.state.as_str(), "open" | "processing" | "closing")
    }
}

struct Network {
    connections: Vec<Connection>,
}

impl Network {
    fn new() -> Network {
        Network {
            connections: (0..10).map(|_| Connection::new("closed")).collect(),
        }
    }

    fn process_event(&mut self, event: &str) {
        for conn in &mut self.connections {
            if conn.is_active() {
                conn.transition(event);
            }
        }
    }
}

struct Simulator {
    network: Network,
    events: Vec<&'static str>,
}

impl Simulator {
    fn new(network: Network) -> Simulator {
        Simulator {
            network,
            events: vec!["open", "data", "complete", "close"],
        }
    }

    fn simulate(&mut self, event_index: usize) {
        self.network.process_event(self.events[event_index]);
        if event_index < self.events.len() - 1 {
            self.simulate(event_index + 1);
        } else {
            self.simulate(0);
        }
    }
}

fn main() {
    let network = Network::new();
    let mut simulator = Simulator::new(network);
    simulator.simulate(0);
}