struct Grid {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            grid: vec![vec![0; size]; size],
            size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else if self.grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = self.grid[i][j];
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in (x as i32 - 1)..=(x as i32 + 1) {
            for j in (y as i32 - 1)..=(y as i32 + 1) {
                if (i != x as i32 || j != y as i32) && i >= 0 && i < self.size as i32 && j >= 0 && j < self.size as i32 {
                    count += self.grid[i as usize][j as usize];
                }
            }
        }
        count
    }
}

struct Simulation {
    grid: Grid,
    steps: usize,
}

impl Simulation {
    fn new(grid: Grid) -> Self {
        Simulation { grid, steps: 0 }
    }

    fn run(&mut self, max_steps: usize) {
        while self.steps < max_steps {
            self.grid.update();
            self.steps += 1;
        }
    }
}

fn main() {
    let size = 50;
    let max_steps = 100;
    let grid = Grid::new(size);
    let mut simulation = Simulation::new(grid);
    simulation.run(max_steps);
}