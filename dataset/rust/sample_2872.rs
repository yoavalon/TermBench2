struct StateMachine {
    state: i32,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine { state: 0 }
    }

    fn transition(&mut self) {
        if self.state == 0 {
            self.state = 1;
        } else if self.state == 1 {
            self.state = 2;
        } else if self.state == 2 {
            self.state = 0;
        }
    }
}

fn main() {
    let mut sm = StateMachine::new();
    loop {
        sm.transition();
        println!("{}", sm.state);
    }
}