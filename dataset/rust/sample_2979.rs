struct NetworkState {
    state: i32,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState { state: 0 }
    }

    fn transition(&mut self) {
        match self.state {
            0 => self.state = 1,
            1 => self.state = 2,
            2 => self.state = 0,
            _ => (),
        }
    }
}

struct ConnectionHandler {
    state_machine: NetworkState,
}

impl ConnectionHandler {
    fn new() -> Self {
        ConnectionHandler {
            state_machine: NetworkState::new(),
        }
    }

    fn process(&mut self) {
        loop {
            self.state_machine.transition();
            self.handle_state();
        }
    }

    fn handle_state(&self) {
        match self.state_machine.state {
            0 => self.state_0(),
            1 => self.state_1(),
            2 => self.state_2(),
            _ => (),
        }
    }

    fn state_0(&self) {
        println!("State 0: Establishing connection");
    }

    fn state_1(&self) {
        println!("State 1: Data transmission");
    }

    fn state_2(&self) {
        println!("State 2: Connection termination");
    }
}

fn main() {
    let mut handler = ConnectionHandler::new();
    handler.process();
}