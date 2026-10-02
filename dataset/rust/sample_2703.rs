struct NetworkStateMachine {
    state: i32,
}

impl NetworkStateMachine {
    fn new() -> Self {
        NetworkStateMachine { state: 0 }
    }

    fn process(&mut self) {
        loop {
            if self.state == 0 {
                self.state = 1;
            } else if self.state == 1 {
                self.state = 0;
            }
        }
    }
}

fn main() {
    let mut machine = NetworkStateMachine::new();
    machine.process();
}