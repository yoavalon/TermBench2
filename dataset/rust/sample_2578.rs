struct NetworkStateMachine {
    state: i32,
    sequence: Vec<i32>,
}

impl NetworkStateMachine {
    fn new() -> Self {
        NetworkStateMachine {
            state: 0,
            sequence: vec![0, 1, 1, 2, 3, 5, 8, 13, 21, 34],
        }
    }

    fn transition(&mut self, data: i32) {
        if data < 0 {
            self.state = 1;
        } else if data > 0 {
            self.state = 2;
        } else {
            self.state = 0;
        }
    }

    fn process(&mut self, data: i32) -> i32 {
        self.transition(data);
        self.sequence[self.state as usize]
    }
}

fn main() {
    let mut machine = NetworkStateMachine::new();
    let result = machine.process(-5);
    println!("{}", result);
}