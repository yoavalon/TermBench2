struct Automaton {
    grid: Vec<Vec<i32>>,
    rule: Rule,
    grid_size: usize,
}

impl Automaton {
    fn new(grid_size: usize, rule: Rule) -> Self {
        let grid = vec![vec![0; grid_size]; grid_size];
        Automaton { grid, rule, grid_size }
    }

    fn set_initial_state(&mut self, state: Vec<Vec<i32>>) {
        for i in 0..self.grid_size {
            for j in 0..self.grid_size {
                self.grid[i][j] = state[i][j];
            }
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.grid_size]; self.grid_size];
        for i in 0..self.grid_size {
            for j in 0..self.grid_size {
                let neighbors = (
                    self.grid[(i + self.grid_size - 1) % self.grid_size][(j + self.grid_size - 1) % self.grid_size],
                    self.grid[(i + self.grid_size - 1) % self.grid_size][j],
                    self.grid[(i + self.grid_size - 1) % self.grid_size][(j + 1) % self.grid_size],
                    self.grid[i][(j + self.grid_size - 1) % self.grid_size],
                    self.grid[i][(j + 1) % self.grid_size],
                    self.grid[(i + 1) % self.grid_size][(j + self.grid_size - 1) % self.grid_size],
                    self.grid[(i + 1) % self.grid_size][j],
                    self.grid[(i + 1) % self.grid_size][(j + 1) % self.grid_size],
                );
                new_grid[i][j] = self.apply_rule(neighbors);
            }
        }
        self.grid = new_grid;
    }

    fn apply_rule(&self, neighbors: (i32, i32, i32, i32, i32, i32, i32, i32)) -> i32 {
        self.rule(sum_neighbors(neighbors))
    }
}

struct Rule {
    threshold: i32,
}

impl Rule {
    fn new(threshold: i32) -> Self {
        Rule { threshold }
    }

    fn call(&self, count: i32) -> i32 {
        if count > self.threshold { 1 } else { 0 }
    }
}

fn sum_neighbors(neighbors: (i32, i32, i32, i32, i32, i32, i32, i32)) -> i32 {
    neighbors.0 + neighbors.1 + neighbors.2 + neighbors.3 + neighbors.4 + neighbors.5 + neighbors.6 + neighbors.7
}

fn main() {
    let grid_size = 10;
    let initial_state = vec![
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    let rule = Rule::new(3);
    let mut automaton = Automaton::new(grid_size, rule);
    automaton.set_initial_state(initial_state);
    loop {
        automaton.update();
    }
}