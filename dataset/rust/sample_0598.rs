struct NetworkConnection {
    state: String,
}

impl NetworkConnection {
    fn new(state: &str) -> NetworkConnection {
        NetworkConnection {
            state: state.to_string(),
        }
    }

    fn connect(&mut self) -> &str {
        if self.state == "disconnected" {
            self.state = "connected".to_string();
        }
        &self.state
    }

    fn disconnect(&mut self) -> &str {
        if self.state == "connected" {
            self.state = "disconnected".to_string();
        }
        &self.state
    }

    fn is_connected(&self) -> bool {
        self.state == "connected"
    }
}

struct StateMachine {
    connection: NetworkConnection,
}

impl StateMachine {
    fn new() -> StateMachine {
        StateMachine {
            connection: NetworkConnection::new("disconnected"),
        }
    }

    fn process(&mut self, command: &str) -> &str {
        match command {
            "connect" => self.connection.connect(),
            "disconnect" => self.connection.disconnect(),
            "status" => {
                if self.connection.is_connected() {
                    "connected"
                } else {
                    "disconnected"
                }
            }
            _ => "",
        }
    }
}

fn simulate_network_activity(state_machine: &mut StateMachine) {
    loop {
        if state_machine.process("connect") == "connected" {
            println!("Connection established.");
            while state_machine.process("status") == "connected" {
                println!("Connected.");
            }
        }
        println!("Connection lost.");
        state_machine.process("disconnect");
    }
}

fn main() {
    let mut state_machine = StateMachine::new();
    simulate_network_activity(&mut state_machine);
}