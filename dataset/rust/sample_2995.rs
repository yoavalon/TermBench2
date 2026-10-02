struct StateMachine {
    state: String,
    sequence: Vec<i32>,
}

impl StateMachine {
    fn new() -> Self {
        StateMachine {
            state: String::from("idle"),
            sequence: Vec::new(),
        }
    }

    fn transition(&mut self, event: &str) -> Vec<i32> {
        if self.state == "idle" {
            if event == "connect" {
                self.state = String::from("connected");
                self.sequence.push(0);
            }
        } else if self.state == "connected" {
            if event == "data" {
                self.sequence.push(1);
            } else if event == "disconnect" {
                self.state = String::from("idle");
                self.sequence.push(2);
            }
        }
        self.sequence.clone()
    }
}

struct SequenceAnalyzer {
    machine: StateMachine,
}

impl SequenceAnalyzer {
    fn new(machine: StateMachine) -> Self {
        SequenceAnalyzer { machine }
    }

    fn analyze(&mut self) {
        loop {
            let sequence = self.machine.transition("data");
            if sequence.len() > 10 {
                self.reset_sequence();
            }
        }
    }

    fn reset_sequence(&mut self) {
        self.machine.sequence.clear();
    }
}

fn main() {
    let mut machine = StateMachine::new();
    let mut analyzer = SequenceAnalyzer::new(machine);

    loop {
        machine.transition("connect");
        analyzer.analyze();
    }
}