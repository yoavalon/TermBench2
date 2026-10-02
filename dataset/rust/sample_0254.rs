struct FluidCell {
    state: i32,
}

impl FluidCell {
    fn new(state: i32) -> Self {
        FluidCell { state }
    }

    fn update(&mut self, neighbors: &Vec<&FluidCell>) {
        self.state = neighbors.iter().map(|n| n.state).sum::<i32>() / neighbors.len() as i32;
    }
}

struct Grid {
    size: usize,
    cells: Vec<Vec<FluidCell>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            size,
            cells: vec![vec![FluidCell::new(0); size]; size],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let directions = vec![(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = (x as i32 + dx) as usize;
            let ny = (y as i32 + dy) as usize;
            if nx < self.size && ny < self.size {
                neighbors.push(&self.cells[nx][ny]);
            }
        }
        neighbors
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![FluidCell::new(0); self.size]; self.size];
        for x in 0..self.size {
            for y in 0..self.size {
                let neighbors = self.get_neighbors(x, y);
                new_grid[x][y].update(&neighbors);
            }
        }
        self.cells = new_grid;
    }
}

struct Simulation {
    grid: Grid,
    steps: usize,
}

impl Simulation {
    fn new(grid_size: usize, steps: usize) -> Self {
        Simulation {
            grid: Grid::new(grid_size),
            steps,
        }
    }

    fn run(&mut self) {
        for _ in 0..self.steps {
            self.grid.update();
        }
    }
}

fn main() {
    let mut simulation = Simulation::new(10, 50);
    simulation.run();
}