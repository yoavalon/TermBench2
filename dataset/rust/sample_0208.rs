struct AutomataGrid {
    grid: Vec<Vec<i32>>,
}

impl AutomataGrid {
    fn new(size: usize) -> Self {
        AutomataGrid {
            grid: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let size = self.grid.len();
        let mut new_grid = vec![vec![0; size]; size];
        for i in 0..size {
            for j in 0..size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if neighbors == 3 {
                    new_grid[i][j] = 1;
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in (x.saturating_sub(1))..=(x + 1).min(self.grid.len() - 1) {
            for j in (y.saturating_sub(1))..=(y + 1).min(self.grid[i].len() - 1) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn boundary_conditions(grid: &mut AutomataGrid, step_limit: usize) {
    let mut steps = 0;
    while steps < step_limit {
        grid.update();
        steps += 1;
    }
}

fn main() {
    let size = 10;
    let step_limit = 100;
    let mut automata = AutomataGrid::new(size);
    boundary_conditions(&mut automata, step_limit);
}