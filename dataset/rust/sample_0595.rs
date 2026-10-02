use rand::Rng;

struct Grid {
    size: usize,
    grid: Vec<Vec<usize>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            size,
            grid: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 1 {
                    new_grid[i][j] = if neighbors == 2 || neighbors == 3 { 1 } else { 0 };
                } else {
                    new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in 0.max(x as isize - 1) as usize..(self.size).min(x + 2) {
            for j in 0.max(y as isize - 1) as usize..(self.size).min(y + 2) {
                if (i, j) != (x, y) {
                    count += self.grid[i][j];
                }
            }
        }
        count
    }
}

struct Simulation {
    grid: Grid,
}

impl Simulation {
    fn new(grid_size: usize) -> Self {
        Simulation {
            grid: Grid::new(grid_size),
        }
    }

    fn populate_grid(&mut self) {
        let mut rng = rand::thread_rng();
        for i in 0..self.grid.size {
            for j in 0..self.grid.size {
                self.grid.grid[i][j] = rng.gen_range(0..2);
            }
        }
    }

    fn run(&mut self) {
        loop {
            self.grid.update();
        }
    }
}

fn main() {
    let mut sim = Simulation::new(10);
    sim.populate_grid();
    sim.run();
}