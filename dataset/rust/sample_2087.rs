use rand::Rng;

struct FluidDynamics {
    grid: Vec<Vec<f64>>,
    viscosity: f64,
    density: f64,
    size: usize,
}

impl FluidDynamics {
    fn new(size: usize, viscosity: f64, density: f64) -> Self {
        let mut rng = rand::thread_rng();
        let grid = (0..size)
            .map(|_| (0..size).map(|_| rng.gen()).collect())
            .collect();
        FluidDynamics {
            grid,
            viscosity,
            density,
            size,
        }
    }

    fn update_velocity(&mut self) {
        let mut laplacian = vec![vec![0.0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let mut sum = 0.0;
                for di in -1..=1 {
                    for dj in -1..=1 {
                        if di == 0 && dj == 0 {
                            continue;
                        }
                        let ni = (i as isize + di) as usize;
                        let nj = (j as isize + dj) as usize;
                        if ni < self.size && nj < self.size {
                            sum += self.grid[ni][nj];
                        }
                    }
                }
                laplacian[i][j] = sum;
            }
        }
        for i in 0..self.size {
            for j in 0..self.size {
                laplacian[i][j] -= 9.0 * self.grid[i][j];
                self.grid[i][j] += self.viscosity * laplacian[i][j] / self.density;
            }
        }
    }

    fn simulate(&mut self, steps: usize) {
        for _ in 0..steps {
            self.update_velocity();
        }
    }
}

struct SimulationController {
    fluid_dynamics: FluidDynamics,
    termination_condition: Box<dyn Fn(&FluidDynamics) -> bool>,
}

impl SimulationController {
    fn new(fluid_dynamics: FluidDynamics, termination_condition: Box<dyn Fn(&FluidDynamics) -> bool>) -> Self {
        SimulationController {
            fluid_dynamics,
            termination_condition,
        }
    }

    fn run(&mut self) {
        for _ in 0..100 {
            self.fluid_dynamics.simulate(10);
            if (self.termination_condition)(&self.fluid_dynamics) {
                break;
            }
        }
    }
}

fn check_condition(fd: &FluidDynamics) -> bool {
    let mean: f64 = fd.grid.iter().flatten().sum::<f64>() / (fd.size * fd.size) as f64;
    fd.grid.iter().all(|row| row.iter().all(|&x| (x - mean).abs() < 1e-8))
}

fn main() {
    let size = 50;
    let viscosity = 0.01;
    let density = 1.0;
    let fluid_dynamics = FluidDynamics::new(size, viscosity, density);
    let termination_condition = Box::new(check_condition);
    let mut controller = SimulationController::new(fluid_dynamics, termination_condition);
    controller.run();
}