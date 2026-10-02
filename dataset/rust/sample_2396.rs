struct FluidCell {
    value: f64,
}

impl FluidCell {
    fn new(value: f64) -> Self {
        FluidCell { value }
    }

    fn update(&mut self, neighbors: &Vec<&FluidCell>) {
        self.value = neighbors.iter().map(|n| n.value).sum::<f64>() / neighbors.len() as f64;
    }
}

struct FluidGrid {
    grid: Vec<Vec<FluidCell>>,
}

impl FluidGrid {
    fn new(size: usize) -> Self {
        FluidGrid {
            grid: vec![vec![FluidCell::new(0.0); size]; size],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = x as isize + dx;
            let ny = y as isize + dy;
            if nx >= 0 && nx < self.grid.len() as isize && ny >= 0 && ny < self.grid.len() as isize {
                neighbors.push(&self.grid[nx as usize][ny as usize]);
            }
        }
        neighbors
    }

    fn update_cells(&mut self) {
        let size = self.grid.len();
        let mut new_grid = vec![vec![FluidCell::new(0.0); size]; size];
        for x in 0..size {
            for y in 0..size {
                let neighbors = self.get_neighbors(x, y);
                new_grid[x][y].update(&neighbors);
            }
        }
        self.grid = new_grid;
    }
}

fn main() {
    let size = 100;
    let mut fluid_grid = FluidGrid::new(size);
    for cell in fluid_grid.grid[0].iter_mut() {
        cell.value = 1.0;
    }
    loop {
        fluid_grid.update_cells();
    }
}