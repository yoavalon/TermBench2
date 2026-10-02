struct FluidCell {
    state: f64,
}

impl FluidCell {
    fn new(state: f64) -> Self {
        FluidCell { state }
    }

    fn update_state(&mut self, neighbors: &[&FluidCell]) {
        self.state = neighbors.iter().map(|n| n.state).sum::<f64>() / neighbors.len() as f64;
    }
}

struct FluidGrid {
    size: usize,
    grid: Vec<Vec<FluidCell>>,
}

impl FluidGrid {
    fn new(size: usize, initial_state: f64) -> Self {
        FluidGrid {
            size,
            grid: vec![vec![FluidCell::new(initial_state); size]; size],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let mut neighbors = Vec::new();
        for dx in -1..=1 {
            for dy in -1..=1 {
                if dx != 0 || dy != 0 {
                    let nx = x as isize + dx;
                    let ny = y as isize + dy;
                    if nx >= 0 && nx < self.size as isize && ny >= 0 && ny < self.size as isize {
                        neighbors.push(&self.grid[nx as usize][ny as usize]);
                    }
                }
            }
        }
        neighbors
    }

    fn update_grid(&mut self) {
        let mut new_grid = vec![vec![FluidCell::new(0.0); self.size]; self.size];
        for x in 0..self.size {
            for y in 0..self.size {
                let neighbors = self.get_neighbors(x, y);
                new_grid[x][y].update_state(&neighbors);
            }
        }
        self.grid = new_grid;
    }
}

fn main() {
    let size = 10;
    let initial_state = 1.0;
    let mut grid = FluidGrid::new(size, initial_state);
    loop {
        grid.update_grid();
    }
}