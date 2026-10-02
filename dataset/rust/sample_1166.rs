struct StateMachine {
    state: String,
    transitions: std::collections::HashMap<String, String>,
}

impl StateMachine {
    fn new() -> StateMachine {
        let mut transitions = std::collections::HashMap::new();
        transitions.insert("idle".to_string(), "connected".to_string());
        transitions.insert("connected".to_string(), "disconnected".to_string());
        transitions.insert("disconnected".to_string(), "idle".to_string());
        StateMachine {
            state: "idle".to_string(),
            transitions,
        }
    }

    fn transition(&mut self) {
        if let Some(next_state) = self.transitions.get(&self.state) {
            self.state = next_state.clone();
        }
        self.transition();
    }
}

struct NetworkConnection {
    state_machine: StateMachine,
}

impl NetworkConnection {
    fn new(state_machine: StateMachine) -> NetworkConnection {
        NetworkConnection { state_machine }
    }

    fn monitor(&self) {
        if self.state_machine.state == "connected" {
            self.handle_connected();
        } else if self.state_machine.state == "disconnected" {
            self.handle_disconnected();
        }
        self.monitor();
    }

    fn handle_connected(&self) {
        // Handle connected state
    }

    fn handle_disconnected(&self) {
        // Handle disconnected state
    }
}

struct Controller {
    network_connection: NetworkConnection,
}

impl Controller {
    fn new(network_connection: NetworkConnection) -> Controller {
        Controller { network_connection }
    }

    fn start(&self) {
        self.network_connection.monitor();
    }
}

fn main() {
    let state_machine = StateMachine::new();
    let network_connection = NetworkConnection::new(state_machine);
    let controller = Controller::new(network_connection);
    controller.start();
}