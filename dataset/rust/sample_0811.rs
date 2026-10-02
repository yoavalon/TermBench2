struct FluidSimulator {
    grid: Vec<Vec<i32>>,
    steps: i32,
    step_count: i32,
}

impl FluidSimulator {
    fn new(grid_size: usize, steps: i32) -> Self {
        FluidSimulator {
            grid: vec![vec![0; grid_size]; grid_size],
            steps,
            step_count: 0,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.grid.len()]; self.grid.len()];
        for i in 0..self.grid.len() {
            for j in 0..self.grid[i].len() {
                let neighbors = self.count_neighbors(i as i32, j as i32);
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
        self.step_count += 1;
    }

    fn count_neighbors(&self, x: i32, y: i32) -> i32 {
        let mut count = 0;
        for i in x - 1..=x + 1 {
            for j in y - 1..=y + 1 {
                if (i != x || j != y) && i >= 0 && i < self.grid.len() as i32 && j >= 0 && j < self.grid[i as usize].len() as i32 {
                    count += self.grid[i as usize][j as usize];
                }
            }
        }
        count
    }

    fn run(&mut self) {
        if self.step_count < self.steps {
            self.update();
            self.run();
        }
    }
}

fn main() {
    let mut sim = FluidSimulator::new(10, 100);
    sim.run();
    for row in sim.grid {
        println!("{:?}", row);
    }
}