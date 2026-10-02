struct FluidCell {
    state: i32,
}

impl FluidCell {
    fn new(state: i32) -> Self {
        FluidCell { state }
    }

    fn update_state(&mut self, neighbors: &Vec<&FluidCell>) {
        let active_neighbors = neighbors.iter().filter(|&&cell| cell.state == 1).count();
        if active_neighbors == 2 || active_neighbors == 3 {
            self.state = 1;
        } else {
            self.state = 0;
        }
    }
}

struct Grid {
    size: usize,
    grid: Vec<Vec<FluidCell>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            size,
            grid: vec![vec![FluidCell::new(0); size]; size],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let directions = vec![(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        let mut neighbors = Vec::new();
        for &(dx, dy) in &directions {
            let nx = (x as isize + dx) as usize;
            let ny = (y as isize + dy) as usize;
            if nx < self.size && ny < self.size {
                neighbors.push(&self.grid[nx][ny]);
            }
        }
        neighbors
    }

    fn update_grid(&mut self) {
        let mut new_grid = vec![vec![FluidCell::new(0); self.size]; self.size];
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
    let grid_size = 50;
    let mut simulation = Grid::new(grid_size);
    loop {
        simulation.update_grid();
    }
}