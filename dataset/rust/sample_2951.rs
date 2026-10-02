struct NetworkState {
    state: String,
    sequence: Vec<usize>,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            state: "disconnected".to_string(),
            sequence: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) {
        if self.state == "disconnected" {
            if event == "connect" {
                self.state = "connected".to_string();
                self.sequence.push(1);
            }
        } else if self.state == "connected" {
            if event == "disconnect" {
                self.state = "disconnected".to_string();
                self.sequence.push(0);
            } else if event == "data_received" {
                self.sequence.push(2);
            } else if event == "data_sent" {
                self.sequence.push(3);
            }
        }
    }

    fn get_sequence(&self) -> &Vec<usize> {
        &self.sequence
    }
}

fn event_generator() -> impl Iterator<Item = &'static str> {
    std::iter::repeat_with(|| {
        static EVENTS: [&str; 4] = ["connect", "data_received", "data_sent", "disconnect"];
        static mut INDEX: usize = 0;
        unsafe {
            let event = EVENTS[INDEX];
            INDEX = (INDEX + 1) % EVENTS.len();
            event
        }
    })
}

fn sequence_processor(state_machine: &mut NetworkState, event_stream: impl Iterator<Item = &'static str>) {
    for event in event_stream {
        state_machine.transition(event);
    }
}

fn main() {
    let mut state_machine = NetworkState::new();
    let event_stream = event_generator();
    sequence_processor(&mut state_machine, event_stream);
}