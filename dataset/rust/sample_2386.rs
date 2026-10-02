struct FluidSimulator {
    grid: Vec<Vec<f64>>,
    size: usize,
}

impl FluidSimulator {
    fn new(size: usize) -> Self {
        let grid = vec![vec![0.0; size]; size];
        FluidSimulator { grid, size }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0.0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                new_grid[i][j] = self.grid[i][j] + self.calculate_flow(i, j);
            }
        }
        self.grid = new_grid;
    }

    fn calculate_flow(&self, x: usize, y: usize) -> f64 {
        let mut flow = 0.0;
        for dx in -1..=1 {
            for dy in -1..=1 {
                if dx == 0 && dy == 0 {
                    continue;
                }
                let nx = x as isize + dx;
                let ny = y as isize + dy;
                if nx >= 0 && nx < self.size as isize && ny >= 0 && ny < self.size as isize {
                    flow += self.grid[nx as usize][ny as usize] * 0.1;
                }
            }
        }
        flow
    }
}

struct FluidController {
    simulator: FluidSimulator,
}

impl FluidController {
    fn new(simulator: FluidSimulator) -> Self {
        FluidController { simulator }
    }

    fn run(&mut self) {
        loop {
            self.simulator.update();
        }
    }
}

fn main() {
    let size = 10;
    let simulator = FluidSimulator::new(size);
    let mut controller = FluidController::new(simulator);
    controller.run();
}