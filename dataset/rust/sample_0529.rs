struct Grid {
    grid: Vec<Vec<i32>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            grid: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.grid.len()]; self.grid.len()];
        for i in 0..self.grid.len() {
            for j in 0..self.grid[i].len() {
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

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in x.saturating_sub(1)..=x + 1 {
            for j in y.saturating_sub(1)..=y + 1 {
                if (i != x || j != y) && i < self.grid.len() && j < self.grid[i].len() {
                    count += self.grid[i][j];
                }
            }
        }
        count
    }
}

struct Simulation {
    grid: Grid,
}

impl Simulation {
    fn new(grid_size: usize) -> Self {
        Simulation {
            grid: Grid::new(grid_size),
        }
    }

    fn run(&mut self) {
        loop {
            self.grid.update();
        }
    }
}

fn main() {
    let mut simulation = Simulation::new(10);
    simulation.run();
}