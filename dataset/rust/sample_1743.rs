struct FluidCell {
    state: i32,
}

impl FluidCell {
    fn new(state: i32) -> FluidCell {
        FluidCell { state }
    }

    fn update_state(&mut self, neighbors: &Vec<&FluidCell>) {
        self.state = neighbors.iter().map(|n| n.state).sum::<i32>() / 3;
    }
}

struct Grid {
    size: usize,
    cells: Vec<Vec<FluidCell>>,
}

impl Grid {
    fn new(size: usize) -> Grid {
        Grid {
            size,
            cells: vec![vec![FluidCell::new(0); size]; size],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let mut neighbors = Vec::new();
        for dx in -1..=1 {
            for dy in -1..=1 {
                if dx == 0 && dy == 0 {
                    continue;
                }
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                if nx >= 0 && nx < self.size as i32 && ny >= 0 && ny < self.size as i32 {
                    neighbors.push(&self.cells[nx as usize][ny as usize]);
                }
            }
        }
        neighbors
    }

    fn update_grid(&mut self) {
        let mut new_cells = vec![vec![FluidCell::new(0); self.size]; self.size];
        for x in 0..self.size {
            for y in 0..self.size {
                let neighbors = self.get_neighbors(x, y);
                new_cells[x][y].update_state(&neighbors);
            }
        }
        self.cells = new_cells;
    }
}

fn main() {
    let grid_size = 10;
    let mut grid = Grid::new(grid_size);
    loop {
        grid.update_grid();
    }
}