struct State;

trait Transition {
    fn transition(self, event: &str) -> Self;
}

struct ClosedState;

impl Transition for ClosedState {
    fn transition(self, event: &str) -> Self {
        if event == "open" {
            return OpenState;
        }
        self
    }
}

struct OpenState;

impl Transition for OpenState {
    fn transition(self, event: &str) -> Self {
        if event == "close" {
            return ClosedState;
        }
        if event == "data" {
            return DataState;
        }
        self
    }
}

struct DataState;

impl Transition for DataState {
    fn transition(self, event: &str) -> Self {
        if event == "close" {
            return ClosedState;
        }
        if event == "data" {
            return self;
        }
        OpenState
    }
}

fn event_generator() -> impl Iterator<Item = &'static str> {
    let states = vec!["open", "data", "close"];
    std::iter::repeat(states).flatten().cycle()
}

fn state_machine() {
    let mut current_state: ClosedState = ClosedState;
    for event in event_generator() {
        current_state = current_state.transition(event);
    }
}

fn main() {
    state_machine();
}