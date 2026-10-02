struct CellularAutomata {
    grid: Vec<Vec<i32>>,
}

impl CellularAutomata {
    fn new(size: usize) -> Self {
        CellularAutomata {
            grid: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let size = self.grid.len();
        let mut new_grid = vec![vec![0; size]; size];
        for i in 0..size {
            for j in 0..size {
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
        let size = self.grid.len();
        let mut count = 0;
        for i in max(0, x - 1)..min(size, x + 2) {
            for j in max(0, y - 1)..min(size, y + 2) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn main() {
    let size = 10;
    let mut ca = CellularAutomata::new(size);
    ca.grid[1][1] = 1;
    ca.grid[2][2] = 1;
    ca.grid[2][3] = 1;
    ca.grid[3][1] = 1;
    ca.grid[3][2] = 1;
    loop {
        ca.update();
        for row in &ca.grid {
            println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
        }
        println!();
    }
}