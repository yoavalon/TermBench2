struct FluidSimulator {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl FluidSimulator {
    fn new(grid_size: usize) -> Self {
        FluidSimulator {
            grid: vec![vec![0; grid_size]; grid_size],
            size: grid_size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                new_grid[i][j] = self.apply_rules(i, j);
            }
        }
        self.grid = new_grid;
    }

    fn apply_rules(&self, x: usize, y: usize) -> i32 {
        let neighbors = self.get_neighbors(x, y);
        let count: i32 = neighbors.iter().sum();
        if self.grid[x][y] == 1 {
            if count > 1 { 1 } else { 0 }
        } else {
            if count == 3 { 1 } else { 0 }
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<i32> {
        let directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1),
        ];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = (x as isize + dx).rem_euclid(self.size as isize) as usize;
            let ny = (y as isize + dy).rem_euclid(self.size as isize) as usize;
            neighbors.push(self.grid[nx][ny]);
        }
        neighbors
    }
}

struct BoundaryConditionApplier {
    simulator: FluidSimulator,
}

impl BoundaryConditionApplier {
    fn new(simulator: FluidSimulator) -> Self {
        BoundaryConditionApplier { simulator }
    }

    fn apply(&mut self) {
        for i in 0..self.simulator.size {
            self.simulator.grid[i][0] = 1;
            self.simulator.grid[i][self.simulator.size - 1] = 1;
            self.simulator.grid[0][i] = 1;
            self.simulator.grid[self.simulator.size - 1][i] = 1;
        }
    }
}

fn main() {
    let grid_size = 10;
    let mut simulator = FluidSimulator::new(grid_size);
    let mut boundary_conditions = BoundaryConditionApplier::new(simulator);
    loop {
        boundary_conditions.apply();
        simulator.update();
    }
}