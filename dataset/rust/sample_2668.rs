struct CellularAutomata {
    size: usize,
    rule: u32,
    state: Vec<u8>,
}

impl CellularAutomata {
    fn new(size: usize, rule: u32) -> Self {
        let mut state = vec![0; size];
        state[size / 2] = 1;
        CellularAutomata { size, rule, state }
    }

    fn apply_rule(&self, left: u8, center: u8, right: u8) -> u8 {
        let index = 4 * left + 2 * center + right;
        ((self.rule >> index) & 1) as u8
    }

    fn next_generation(&mut self) {
        let mut new_state = vec![0; self.size];
        for i in 0..self.size {
            let left = self.state[(i + self.size - 1) % self.size];
            let center = self.state[i];
            let right = self.state[(i + 1) % self.size];
            new_state[i] = self.apply_rule(left, center, right);
        }
        self.state = new_state;
    }

    fn run(&mut self, steps: usize) -> Vec<Vec<u8>> {
        let mut results = Vec::new();
        for _ in 0..steps {
            results.push(self.state.clone());
            self.next_generation();
        }
        results
    }
}

fn generate_sequence(size: usize, rule: u32, steps: usize) -> Vec<Vec<u8>> {
    let mut ca = CellularAutomata::new(size, rule);
    ca.run(steps)
}

fn display_sequence(sequence: Vec<Vec<u8>>) {
    for row in sequence {
        println!("{}", row.iter().map(|&cell| if cell == 1 { '1' } else { '0' }).collect::<String>());
    }
}

fn main() {
    let size = 31;
    let rule = 30;
    let steps = 10;
    let sequence = generate_sequence(size, rule, steps);
    display_sequence(sequence);
}