struct CellularAutomaton {
    grid: Vec<Vec<i32>>,
    rule: i32,
}

impl CellularAutomaton {
    fn new(grid_size: usize, rule: i32) -> Self {
        let grid = vec![vec![0; grid_size]; grid_size];
        CellularAutomaton { grid, rule }
    }

    fn update_grid(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 0..self.grid.len() {
            for j in 0..self.grid[i].len() {
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
        for i in (0.max(x as i32 - 1)) as usize..(self.grid.len().min(x + 2)) {
            for j in (0.max(y as i32 - 1)) as usize..(self.grid[i].len().min(y + 2)) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }

    fn apply_rule(&self, state: i32, neighbors: i32) -> i32 {
        if self.rule == 1 {
            if state == 0 && neighbors == 3 {
                return 1;
            } else if state == 1 && (neighbors < 2 || neighbors > 3) {
                return 0;
            } else {
                return state;
            }
        }
        state
    }
}

fn main() {
    let mut automaton = CellularAutomaton::new(100, 1);
    loop {
        automaton.update_grid();
    }
}