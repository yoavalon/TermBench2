struct Grid {
    size: usize,
    state: Vec<Vec<i32>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        let state = vec![vec![0; size]; size];
        Grid { size, state }
    }

    fn update(&mut self) {
        let mut new_state = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                let alive_neighbors = neighbors.iter().sum::<i32>();
                if self.state[i][j] == 1 {
                    new_state[i][j] = if 2 <= alive_neighbors && alive_neighbors <= 3 { 1 } else { 0 };
                } else {
                    new_state[i][j] = if alive_neighbors == 3 { 1 } else { 0 };
                }
            }
        }
        self.state = new_state;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<i32> {
        let mut neighbors = Vec::new();
        for i in max(0, x as i32 - 1)..=min(self.size as i32, x as i32 + 1) {
            for j in max(0, y as i32 - 1)..=min(self.size as i32, y as i32 + 1) {
                if (i, j) != (x as i32, y as i32) {
                    neighbors.push(self.state[i as usize][j as usize]);
                }
            }
        }
        neighbors
    }
}

struct Simulation {
    grid: Grid,
    iteration: usize,
}

impl Simulation {
    fn new(grid_size: usize) -> Self {
        let grid = Grid::new(grid_size);
        Simulation { grid, iteration: 0 }
    }

    fn run(&mut self) {
        loop {
            self.grid.update();
            self.iteration += 1;
        }
    }
}

fn main() {
    let mut sim = Simulation::new(10);
    sim.run();
}