struct NetworkStateMachine {
    states: Vec<&'static str>,
    transitions: std::collections::HashMap<(&'static str, &'static str), &'static str>,
    current_state: &'static str,
}

impl NetworkStateMachine {
    fn new(states: Vec<&'static str>, transitions: std::collections::HashMap<(&'static str, &'static str), &'static str>) -> Self {
        NetworkStateMachine {
            states,
            transitions,
            current_state: states[0],
        }
    }

    fn transition(&mut self, event: &str) {
        if let Some(&next_state) = self.transitions.get(&(self.current_state, event)) {
            self.current_state = next_state;
        } else {
            panic!("Invalid transition");
        }
    }

    fn is_terminal(&self) -> bool {
        self.current_state == "disconnected" || self.current_state == "error"
    }
}

struct EventManager {
    events: Vec<&'static str>,
    index: usize,
}

impl EventManager {
    fn new(events: Vec<&'static str>) -> Self {
        EventManager {
            events,
            index: 0,
        }
    }

    fn get_next_event(&mut self) -> Option<&'static str> {
        if self.index < self.events.len() {
            let event = self.events[self.index];
            self.index += 1;
            Some(event)
        } else {
            None
        }
    }
}

fn main() {
    let states = vec!["idle", "connected", "disconnected", "error"];
    let transitions = std::collections::HashMap::from([
        (("idle", "connect"), "connected"),
        (("connected", "disconnect"), "disconnected"),
        (("connected", "error"), "error"),
        (("disconnected", "connect"), "connected"),
        (("error", "reset"), "idle"),
    ]);
    let events = vec!["connect", "disconnect", "error", "reset", "connect", "disconnect", "connect", "error", "reset"];
    let mut network_machine = NetworkStateMachine::new(states, transitions);
    let mut event_manager = EventManager::new(events);
    loop {
        let event = event_manager.get_next_event();
        if event.is_none() || network_machine.is_terminal() {
            break;
        }
        network_machine.transition(event.unwrap());
    }
    println!("Final state: {}", network_machine.current_state);
}