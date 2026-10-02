struct FluidCell {
    pressure: f64,
    velocity: f64,
}

impl FluidCell {
    fn new(pressure: f64, velocity: f64) -> Self {
        FluidCell { pressure, velocity }
    }

    fn update_state(&mut self, neighbor_states: &Vec<&FluidCell>) {
        let new_pressure = neighbor_states.iter().map(|state| state.pressure).sum::<f64>() / neighbor_states.len() as f64;
        let new_velocity = neighbor_states.iter().map(|state| state.velocity).sum::<f64>() / neighbor_states.len() as f64;
        self.pressure = new_pressure;
        self.velocity = new_velocity;
    }
}

fn initialize_grid(size: usize, initial_pressure: f64, initial_velocity: f64) -> Vec<Vec<FluidCell>> {
    let mut grid = Vec::with_capacity(size);
    for _ in 0..size {
        let row = vec![FluidCell::new(initial_pressure, initial_velocity); size];
        grid.push(row);
    }
    grid
}

fn simulate(mut grid: Vec<Vec<FluidCell>>) {
    let size = grid.len();
    loop {
        let mut new_grid = vec![vec![FluidCell::new(0.0, 0.0); size]; size];
        for i in 0..size {
            for j in 0..size {
                let mut neighbors = Vec::new();
                for di in [-1, 0, 1] {
                    for dj in [-1, 0, 1] {
                        if di == 0 && dj == 0 {
                            continue;
                        }
                        let ni = i as isize + di;
                        let nj = j as isize + dj;
                        if ni >= 0 && ni < size as isize && nj >= 0 && nj < size as isize {
                            neighbors.push(&grid[ni as usize][nj as usize]);
                        }
                    }
                }
                new_grid[i][j].update_state(&neighbors);
            }
        }
        grid = new_grid;
    }
}

fn main() {
    let grid_size = 10;
    let initial_pressure = 1.0;
    let initial_velocity = 0.0;
    let grid = initialize_grid(grid_size, initial_pressure, initial_velocity);
    simulate(grid);
}