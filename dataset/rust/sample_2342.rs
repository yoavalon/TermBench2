struct FluidCell {
    state: f64,
}

impl FluidCell {
    fn new(state: f64) -> Self {
        FluidCell { state }
    }

    fn update(&mut self, neighbors: &Vec<&FluidCell>) {
        let avg_state: f64 = neighbors.iter().map(|n| n.state).sum::<f64>() / neighbors.len() as f64;
        self.state = avg_state;
    }
}

struct Grid {
    size: usize,
    cells: Vec<Vec<FluidCell>>,
}

impl Grid {
    fn new(size: usize, initial_state: f64) -> Self {
        Grid {
            size,
            cells: vec![vec![FluidCell::new(initial_state); size]; size],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let mut neighbors = Vec::new();
        for dx in [-1, 0, 1] {
            for dy in [-1, 0, 1] {
                if dx == 0 && dy == 0 {
                    continue;
                }
                let nx = x as isize + dx;
                let ny = y as isize + dy;
                if nx >= 0 && nx < self.size as isize && ny >= 0 && ny < self.size as isize {
                    neighbors.push(&self.cells[nx as usize][ny as usize]);
                }
            }
        }
        neighbors
    }

    fn update(&mut self) {
        let mut new_cells = vec![vec![FluidCell::new(self.cells[x][y].state); self.size]; self.size];
        for x in 0..self.size {
            for y in 0..self.size {
                let neighbors = self.get_neighbors(x, y);
                new_cells[x][y].update(&neighbors);
            }
        }
        self.cells = new_cells;
    }
}

fn main() {
    let grid_size = 10;
    let initial_state = 0.5;
    let mut grid = Grid::new(grid_size, initial_state);
    loop {
        grid.update();
    }
}