struct AutomataSimulator {
    grid: Vec<Vec<i32>>,
    rule: Vec<Vec<i32>>,
    size: usize,
}

impl AutomataSimulator {
    fn new(size: usize, rule: Vec<Vec<i32>>) -> Self {
        let grid = vec![vec![0; size]; size];
        AutomataSimulator { grid, rule, size }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let state = self.grid[i][j];
                let neighbors = self.count_neighbors(i, j);
                let new_state = self.apply_rule(state, neighbors);
                new_grid[i][j] = new_state;
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in x.saturating_sub(1)..=x + 1 {
            for j in y.saturating_sub(1)..=y + 1 {
                if i < self.size && j < self.size && !(i == x && j == y) {
                    count += self.grid[i][j];
                }
            }
        }
        count
    }

    fn apply_rule(&self, state: i32, neighbors: i32) -> i32 {
        self.rule[state as usize][neighbors as usize]
    }
}

fn main() {
    let size = 10;
    let rule = vec![
        vec![0, 1, 1, 1, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 1, 0, 0, 0, 0, 0],
    ];
    let mut automata = AutomataSimulator::new(size, rule);
    for _ in 0..100 {
        automata.update();
    }
    println!("{:?}", automata.grid);
}