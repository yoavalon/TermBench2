struct FluidSim {
    size: usize,
    grid: Vec<Vec<f64>>,
    diffusion_rate: f64,
}

impl FluidSim {
    fn new(size: usize, diffusion_rate: f64) -> Self {
        let grid = vec![vec![0.0; size]; size];
        FluidSim {
            size,
            grid,
            diffusion_rate,
        }
    }

    fn update_grid(&mut self) {
        let mut new_grid = vec![vec![0.0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let mut total = self.grid[i][j];
                let mut neighbors = 0;
                if i > 0 {
                    total += self.grid[i - 1][j];
                    neighbors += 1;
                }
                if i < self.size - 1 {
                    total += self.grid[i + 1][j];
                    neighbors += 1;
                }
                if j > 0 {
                    total += self.grid[i][j - 1];
                    neighbors += 1;
                }
                if j < self.size - 1 {
                    total += self.grid[i][j + 1];
                    neighbors += 1;
                }
                new_grid[i][j] = self.grid[i][j] + self.diffusion_rate * (total / neighbors as f64 - self.grid[i][j]);
            }
        }
        self.grid = new_grid;
    }

    fn add_source(&mut self, x: usize, y: usize, amount: f64) {
        self.grid[x][y] += amount;
    }
}

struct SimulationRunner {
    sim: FluidSim,
}

impl SimulationRunner {
    fn new(sim: FluidSim) -> Self {
        SimulationRunner { sim }
    }

    fn run(&mut self) {
        loop {
            self.sim.update_grid();
            self.sim.add_source(self.sim.size / 2, self.sim.size / 2, 0.1);
        }
    }
}

fn main() {
    let sim = FluidSim::new(100, 0.01);
    let mut runner = SimulationRunner::new(sim);
    runner.run();
}