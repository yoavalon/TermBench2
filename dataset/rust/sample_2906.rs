struct StateSimulator {
    state: i32,
    rules: Vec<(Box<dyn Fn(i32) -> bool>, Box<dyn Fn(i32) -> i32>)>,
}

impl StateSimulator {
    fn new(initial_state: i32, transition_rules: Vec<(Box<dyn Fn(i32) -> bool>, Box<dyn Fn(i32) -> i32>)>) -> Self {
        StateSimulator {
            state: initial_state,
            rules: transition_rules,
        }
    }

    fn update(&mut self) {
        let mut new_state = self.state;
        for rule in &self.rules {
            if (rule.0)(self.state) {
                new_state = (rule.1)(self.state);
                break;
            }
        }
        self.state = new_state;
    }
}

struct SequenceGenerator {
    simulator: StateSimulator,
    sequence: Vec<i32>,
}

impl SequenceGenerator {
    fn new(simulator: StateSimulator) -> Self {
        SequenceGenerator {
            simulator,
            sequence: Vec::new(),
        }
    }

    fn generate(&mut self) {
        loop {
            self.sequence.push(self.simulator.state);
            self.simulator.update();
        }
    }
}

struct AnalysisTool {
    sequence: Vec<i32>,
}

impl AnalysisTool {
    fn new(sequence: Vec<i32>) -> Self {
        AnalysisTool { sequence }
    }

    fn analyze(&self) {
        loop {
            println!("{}", self.sequence[self.sequence.len() - 1]);
        }
    }
}

fn main() {
    let initial_state = 0;
    let transition_rules = vec![
        (Box::new(|x: i32| x < 10), Box::new(|x: i32| x + 1)),
        (Box::new(|_: i32| true), Box::new(|x: i32| x)),
    ];
    let simulator = StateSimulator::new(initial_state, transition_rules);
    let mut generator = SequenceGenerator::new(simulator);
    let tool = AnalysisTool::new(generator.sequence.clone());
    generator.generate();
    tool.analyze();
}