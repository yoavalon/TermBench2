struct FluidSimulator {
    size: usize,
    state: Vec<Vec<usize>>,
}

impl FluidSimulator {
    fn new(size: usize, initial_state: Vec<Vec<usize>>) -> Self {
        FluidSimulator { size, state: initial_state }
    }

    fn update_state(&mut self) {
        let mut new_state = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                new_state[i][j] = self.apply_rules(&neighbors);
            }
        }
        self.state = new_state;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<usize> {
        let directions = vec![(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = (x as isize + dx) as usize;
            let ny = (y as isize + dy) as usize;
            if nx < self.size && ny < self.size {
                neighbors.push(self.state[nx][ny]);
            }
        }
        neighbors
    }

    fn apply_rules(&self, neighbors: &[usize]) -> usize {
        let active_neighbors = neighbors.iter().sum::<usize>();
        if self.state[0][0] == 1 {
            if active_neighbors >= 2 {
                1
            } else {
                0
            }
        } else {
            if active_neighbors == 3 {
                1
            } else {
                0
            }
        }
    }
}

fn initialize_grid(size: usize) -> Vec<Vec<usize>> {
    (0..size)
        .map(|i| {
            (0..size)
                .map(|j| if i % 2 == 1 && j % 2 == 1 { 0 } else { 1 })
                .collect()
        })
        .collect()
}

fn main() {
    let grid_size = 10;
    let initial_state = initialize_grid(grid_size);
    let mut simulator = FluidSimulator::new(grid_size, initial_state);
    loop {
        simulator.update_state();
    }
}