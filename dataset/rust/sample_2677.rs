use std::collections::HashMap;

struct StateMachine {
    states: HashMap<String, Vec<String>>,
    transitions: HashMap<(String, String), String>,
    current_state: String,
    sequence: Vec<String>,
}

impl StateMachine {
    fn new(states: HashMap<String, Vec<String>>, transitions: HashMap<(String, String), String>, start_state: String) -> Self {
        StateMachine {
            states,
            transitions,
            current_state: start_state,
            sequence: Vec::new(),
        }
    }

    fn transition(&mut self, event: String) {
        if let Some(&next_state) = self.transitions.get(&(self.current_state.clone(), event)) {
            self.current_state = next_state;
            self.sequence.push(event);
        } else {
            panic!("Invalid transition");
        }
    }

    fn is_terminated(&self) -> bool {
        self.states.get("terminal").unwrap_or(&vec![]).contains(&self.current_state)
    }
}

struct NetworkConnection {
    state_machine: StateMachine,
}

impl NetworkConnection {
    fn new(state_machine: StateMachine) -> Self {
        NetworkConnection { state_machine }
    }

    fn process_events(&mut self, events: Vec<String>) {
        for event in events {
            self.state_machine.transition(event);
            if self.state_machine.is_terminated() {
                break;
            }
        }
    }
}

fn main() {
    let mut states: HashMap<String, Vec<String>> = HashMap::new();
    states.insert("initial".to_string(), vec!["connected".to_string(), "disconnected".to_string()]);
    states.insert("connected".to_string(), vec!["sending".to_string(), "receiving".to_string(), "disconnected".to_string()]);
    states.insert("sending".to_string(), vec!["connected".to_string(), "disconnected".to_string()]);
    states.insert("receiving".to_string(), vec!["connected".to_string(), "disconnected".to_string()]);
    states.insert("terminal".to_string(), vec!["disconnected".to_string()]);

    let mut transitions: HashMap<(String, String), String> = HashMap::new();
    transitions.insert(("initial".to_string(), "connect".to_string()), "connected".to_string());
    transitions.insert(("connected".to_string(), "send".to_string()), "sending".to_string());
    transitions.insert(("connected".to_string(), "receive".to_string()), "receiving".to_string());
    transitions.insert(("connected".to_string(), "disconnect".to_string()), "disconnected".to_string());
    transitions.insert(("sending".to_string(), "connect".to_string()), "connected".to_string());
    transitions.insert(("sending".to_string(), "disconnect".to_string()), "disconnected".to_string());
    transitions.insert(("receiving".to_string(), "connect".to_string()), "connected".to_string());
    transitions.insert(("receiving".to_string(), "disconnect".to_string()), "disconnected".to_string());

    let start_state = "initial".to_string();
    let state_machine = StateMachine::new(states, transitions, start_state);
    let mut network_connection = NetworkConnection::new(state_machine);
    let events = vec!["connect".to_string(), "send".to_string(), "receive".to_string(), "disconnect".to_string()];
    network_connection.process_events(events);
    println!("Sequence: {:?}", network_connection.state_machine.sequence);
    println!("Terminated: {}", network_connection.state_machine.is_terminated());
}