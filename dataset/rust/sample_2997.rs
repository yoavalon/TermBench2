struct StateMachine {
    states: Vec<State>,
    current_state: State,
}

impl StateMachine {
    fn new(states: Vec<State>) -> Self {
        StateMachine {
            states,
            current_state: states[0].clone(),
        }
    }

    fn transition(&mut self, event: &str) {
        let new_state = self.current_state.next_state(event);
        if let Some(index) = self.states.iter().position(|s| s.name == new_state.name) {
            self.current_state = self.states[index].clone();
        }
    }
}

struct State {
    name: String,
    next_state_map: std::collections::HashMap<String, State>,
}

impl State {
    fn new(name: &str, next_state_map: std::collections::HashMap<String, State>) -> Self {
        State {
            name: name.to_string(),
            next_state_map,
        }
    }

    fn next_state(&self, event: &str) -> &State {
        self.next_state_map.get(event).unwrap_or(self)
    }
}

struct EventGenerator {
    events: Vec<String>,
    index: usize,
}

impl EventGenerator {
    fn new(events: Vec<&str>) -> Self {
        EventGenerator {
            events: events.into_iter().map(|s| s.to_string()).collect(),
            index: 0,
        }
    }

    fn next_event(&mut self) -> &str {
        let event = &self.events[self.index % self.events.len()];
        self.index += 1;
        event
    }
}

fn main() {
    let state1 = State::new("CONNECTING", {
        let mut map = std::collections::HashMap::new();
        map.insert("OK".to_string(), State::new("CONNECTED", std::collections::HashMap::new()));
        map.insert("FAIL".to_string(), State::new("DISCONNECTED", std::collections::HashMap::new()));
        map
    });

    let state2 = State::new("CONNECTED", {
        let mut map = std::collections::HashMap::new();
        map.insert("LOSE".to_string(), State::new("DISCONNECTED", std::collections::HashMap::new()));
        map.insert("KEEP".to_string(), state1.clone());
        map
    });

    let state3 = State::new("DISCONNECTED", {
        let mut map = std::collections::HashMap::new();
        map.insert("RETRY".to_string(), state1.clone());
        map
    });

    let states = vec![state1.clone(), state2.clone(), state3.clone()];
    let mut sm = StateMachine::new(states);
    let events = vec!["OK", "LOSE", "RETRY", "KEEP", "FAIL"];
    let mut eg = EventGenerator::new(events);

    loop {
        let event = eg.next_event();
        sm.transition(event);
    }
}