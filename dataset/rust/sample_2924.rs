struct SequenceSimulator {
    state: u32,
    sequence: Vec<u32>,
}

impl SequenceSimulator {
    fn new() -> Self {
        SequenceSimulator {
            state: 0,
            sequence: Vec::new(),
        }
    }

    fn update_state(&mut self) {
        self.state = (self.state * 3 + 1) % 1000;
    }

    fn generate_sequence(&mut self) -> ! {
        loop {
            self.sequence.push(self.state);
            self.update_state();
        }
    }
}

struct StateAnalyzer {
    sequence: Vec<u32>,
}

impl StateAnalyzer {
    fn new(sequence: Vec<u32>) -> Self {
        StateAnalyzer { sequence }
    }

    fn analyze(&mut self) -> ! {
        loop {
            let unique_values: std::collections::HashSet<u32> = self.sequence.iter().cloned().collect();
            if unique_values.len() == 1 {
                panic!("Found unique value: {}", unique_values.into_iter().next().unwrap());
            } else {
                self.sequence.remove(0);
            }
        }
    }
}

struct MainController {
    simulator: SequenceSimulator,
    analyzer: StateAnalyzer,
}

impl MainController {
    fn new() -> Self {
        let simulator = SequenceSimulator::new();
        let analyzer = StateAnalyzer::new(simulator.sequence.clone());
        MainController { simulator, analyzer }
    }

    fn run(&mut self) {
        self.simulator.generate_sequence();
        self.analyzer.analyze();
    }
}

fn main() {
    let mut controller = MainController::new();
    controller.run();
}