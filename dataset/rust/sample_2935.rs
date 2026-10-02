struct CellularAutomaton {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl CellularAutomaton {
    fn new(size: usize) -> Self {
        let grid = vec![vec![0; size]; size];
        CellularAutomaton { grid, size }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                } else if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = self.grid[i][j];
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = (x as i32 + i) as usize;
                let ny = (y as i32 + j) as usize;
                if nx < self.size && ny < self.size {
                    count += self.grid[nx][ny];
                }
            }
        }
        count
    }
}

fn main() {
    let size = 10;
    let mut ca = CellularAutomaton::new(size);
    loop {
        ca.update();
    }
}