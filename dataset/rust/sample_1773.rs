struct FluidCell {
    state: i32,
}

impl FluidCell {
    fn new(state: i32) -> Self {
        FluidCell { state }
    }

    fn update_state(&mut self, neighbors: &[&FluidCell]) {
        let active_neighbors = neighbors.iter().filter(|&&cell| cell.state > 0).count();
        if active_neighbors > 4 {
            self.state = 2;
        } else if active_neighbors < 2 {
            self.state = 0;
        } else {
            self.state = 1;
        }
    }
}

struct FluidGrid {
    grid: Vec<Vec<FluidCell>>,
    size: usize,
}

impl FluidGrid {
    fn new(size: usize) -> Self {
        FluidGrid {
            grid: vec![vec![FluidCell::new(0); size]; size],
            size,
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let mut neighbors = Vec::new();
        for i in x.saturating_sub(1)..=(x + 1).min(self.size - 1) {
            for j in y.saturating_sub(1)..=(y + 1).min(self.size - 1) {
                if !(i == x && j == y) {
                    neighbors.push(&self.grid[i][j]);
                }
            }
        }
        neighbors
    }

    fn update_grid(&mut self) {
        let mut new_grid = vec![vec![FluidCell::new(0); self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                new_grid[i][j].update_state(&neighbors);
            }
        }
        self.grid = new_grid;
    }
}

fn main() {
    let size = 10;
    let mut grid = FluidGrid::new(size);
    loop {
        grid.update_grid();
    }
}