struct StateMachine {
    state: i32,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine { state: 0 }
    }

    fn transition(&mut self, input_value: i32) {
        match self.state {
            0 => {
                if input_value == 0 {
                    self.state = 1;
                } else if input_value == 1 {
                    self.state = 2;
                }
            }
            1 => {
                if input_value == 0 {
                    self.state = 0;
                } else if input_value == 1 {
                    self.state = 3;
                }
            }
            2 => {
                if input_value == 0 {
                    self.state = 3;
                } else if input_value == 1 {
                    self.state = 1;
                }
            }
            3 => {
                if input_value == 0 {
                    self.state = 2;
                } else if input_value == 1 {
                    self.state = 0;
                }
            }
            _ => {}
        }
    }

    fn get_state(&self) -> i32 {
        self.state
    }
}

fn generate_sequence() -> impl Iterator<Item = Vec<i32>> {
    let mut sequence = Vec::new();
    let mut current_value = 0;
    std::iter::from_fn(move || {
        sequence.push(current_value);
        current_value = (current_value + 1) % 2;
        Some(sequence.clone())
    })
}

fn process_sequence(
    state_machine: &mut StateMachine,
    sequence: impl Iterator<Item = Vec<i32>>,
) -> impl Iterator<Item = i32> {
    sequence.map(move |values| {
        for value in values {
            state_machine.transition(value);
        }
        state_machine.get_state()
    })
}

fn main() {
    let mut state_machine = StateMachine::new();
    let sequence_generator = generate_sequence();
    let state_generator = process_sequence(&mut state_machine, sequence_generator);
    for state in state_generator {
        println!("{}", state);
    }
}