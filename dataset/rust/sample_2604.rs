struct CellularAutomaton {
    size: usize,
    rules: Vec<usize>,
    state: Vec<usize>,
}

impl CellularAutomaton {
    fn new(size: usize, rules: Vec<usize>) -> Self {
        CellularAutomaton {
            size,
            rules,
            state: vec![0; size],
        }
    }

    fn update(&mut self) {
        let mut new_state = vec![0; self.size];
        for i in 0..self.size {
            let left = if i > 0 { self.state[i - 1] } else { self.state[self.size - 1] };
            let right = self.state[(i + 1) % self.size];
            let neighborhood = (left, self.state[i], right);
            let index = neighborhood.0 * 4 + neighborhood.1 * 2 + neighborhood.2;
            new_state[i] = self.rules[index];
        }
        self.state = new_state;
    }

    fn display(&self) -> String {
        self.state.iter().map(|&cell| cell.to_string()).collect()
    }
}

fn generate_rules(rule_number: usize) -> Vec<usize> {
    let mut rules = vec![0; 8];
    for i in 0..8 {
        let neighborhood = (i / 4, i / 2 % 2, i % 2);
        let index = neighborhood.0 * 4 + neighborhood.1 * 2 + neighborhood.2;
        rules[index] = (rule_number >> i) & 1;
    }
    rules
}

fn simulate_automaton(size: usize, rule_number: usize, steps: usize) -> Vec<String> {
    let mut automaton = CellularAutomaton::new(size, generate_rules(rule_number));
    automaton.state[size / 2] = 1;
    let mut result = Vec::new();
    for _ in 0..steps {
        result.push(automaton.display());
        automaton.update();
    }
    result
}

fn main() {
    let size = 31;
    let rule_number = 30;
    let steps = 10;
    for state in simulate_automaton(size, rule_number, steps) {
        println!("{}", state);
    }
}