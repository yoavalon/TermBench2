struct FluidCell {
    state: i32,
}

impl FluidCell {
    fn new(state: i32) -> Self {
        FluidCell { state }
    }

    fn update(&mut self, neighbors: &Vec<&FluidCell>) {
        let new_state = neighbors.iter().map(|n| n.state).sum::<i32>() / neighbors.len() as i32;
        self.state = new_state;
    }
}

struct Grid {
    width: usize,
    height: usize,
    grid: Vec<Vec<FluidCell>>,
}

impl Grid {
    fn new(width: usize, height: usize, initial_state: i32) -> Self {
        Grid {
            width,
            height,
            grid: vec![vec![FluidCell::new(initial_state); width]; height],
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = (x as i32 + dx) as usize;
            let ny = (y as i32 + dy) as usize;
            if nx < self.width && ny < self.height {
                neighbors.push(&self.grid[ny][nx]);
            }
        }
        neighbors
    }

    fn update_cells(&mut self) {
        for y in 0..self.height {
            for x in 0..self.width {
                let neighbors = self.get_neighbors(x, y);
                self.grid[y][x].update(&neighbors);
            }
        }
    }
}

struct Simulation {
    grid: Grid,
}

impl Simulation {
    fn new(grid: Grid) -> Self {
        Simulation { grid }
    }

    fn run(&mut self) {
        loop {
            self.grid.update_cells();
        }
    }
}

fn main() {
    let grid = Grid::new(10, 10, 50);
    let mut simulation = Simulation::new(grid);
    simulation.run();
}