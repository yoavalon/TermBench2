struct CellularAutomata {
    size: usize,
    rule: std::collections::HashMap<(u8, u8, u8), u8>,
    grid: Vec<u8>,
}

impl CellularAutomata {
    fn new(size: usize, rule: std::collections::HashMap<(u8, u8, u8), u8>) -> Self {
        let mut grid = vec![0; size];
        grid[size / 2] = 1;
        CellularAutomata { size, rule, grid }
    }

    fn update(&mut self) {
        let mut new_grid = vec![0; self.size];
        for i in 1..self.size - 1 {
            let pattern = (self.grid[i - 1], self.grid[i], self.grid[i + 1]);
            if let Some(&value) = self.rule.get(&pattern) {
                new_grid[i] = value;
            }
        }
        self.grid = new_grid;
    }

    fn run(&mut self, steps: usize) {
        for _ in 0..steps {
            self.update();
        }
    }
}

fn generate_rule(rule_number: u8) -> std::collections::HashMap<(u8, u8, u8), u8> {
    let mut rule = std::collections::HashMap::new();
    for i in 0..8 {
        let pattern = (
            ((i >> 2) & 1) as u8,
            ((i >> 1) & 1) as u8,
            (i & 1) as u8,
        );
        rule.insert(pattern, (rule_number >> i) & 1);
    }
    rule
}

fn main() {
    let size = 51;
    let rule_number = 30;
    let steps = 10;
    let rule = generate_rule(rule_number);
    let mut ca = CellularAutomata::new(size, rule);
    ca.run(steps);
    for _ in 0..=steps {
        let row: String = ca.grid.iter().map(|&x| if x == 1 { '#' } else { ' ' }).collect();
        println!("{}", row);
    }
}