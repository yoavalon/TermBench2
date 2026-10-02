struct CellularAutomata {
    grid: Vec<Vec<i32>>,
    rule: i32,
    size: usize,
}

impl CellularAutomata {
    fn new(size: usize, rule: i32) -> Self {
        let grid = vec![vec![0; size]; size];
        CellularAutomata { grid, rule, size }
    }

    fn set_initial_state(&mut self, x: usize, y: usize) {
        self.grid[x][y] = 1;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = (x as isize + i + self.size as isize) % self.size as isize;
                let ny = (y as isize + j + self.size as isize) % self.size as isize;
                count += self.grid[nx as usize][ny as usize];
            }
        }
        count
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let n = self.get_neighbors(i, j);
                new_grid[i][j] = self.apply_rule(self.grid[i][j], n);
            }
        }
        self.grid = new_grid;
    }

    fn apply_rule(&self, state: i32, neighbors: i32) -> i32 {
        if state == 0 && neighbors == self.rule {
            1
        } else {
            0
        }
    }
}

fn main() {
    let mut ca = CellularAutomata::new(10, 3);
    ca.set_initial_state(5, 5);
    loop {
        ca.update();
    }
}