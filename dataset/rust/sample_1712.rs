struct CellularAutomata {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl CellularAutomata {
    fn new(size: usize) -> Self {
        let grid = vec![vec![0; size]; size];
        CellularAutomata { grid, size }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
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
        for i in 0.max(x as isize - 1) as usize..(x + 2).min(self.size) {
            for j in 0.max(y as isize - 1) as usize..(y + 2).min(self.size) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn main() {
    let mut ca = CellularAutomata::new(10);
    ca.grid[5][5] = 1;
    ca.grid[5][6] = 1;
    ca.grid[6][5] = 1;
    ca.grid[6][6] = 1;
    loop {
        ca.update();
    }
}