struct Automaton {
    size: usize,
    rule: Vec<u8>,
    state: Vec<u8>,
}

impl Automaton {
    fn new(size: usize, rule: Vec<u8>) -> Automaton {
        let mut state = vec![0; size];
        state[size / 2] = 1;
        Automaton { size, rule, state }
    }

    fn evolve(&mut self) {
        let mut new_state = vec![0; self.size];
        for i in 1..self.size - 1 {
            let pattern = (self.state[i - 1], self.state[i], self.state[i + 1]);
            new_state[i] = self.rule[self.pattern_to_index(pattern)];
        }
        self.state = new_state;
    }

    fn display(&self) -> String {
        self.state.iter().map(|&cell| cell.to_string()).collect()
    }

    fn pattern_to_index(&self, pattern: (u8, u8, u8)) -> usize {
        (pattern.0 as usize) * 4 + (pattern.1 as usize) * 2 + (pattern.2 as usize)
    }
}

fn generate_rule(number: u8) -> Vec<u8> {
    (0..8).map(|i| (number >> i) & 1).collect()
}

fn main() {
    let size = 31;
    let rule_number = 30;
    let rule = generate_rule(rule_number);
    let mut automaton = Automaton::new(size, rule);
    let iterations = 10;
    for _ in 0..iterations {
        println!("{}", automaton.display());
        automaton.evolve();
    }
}