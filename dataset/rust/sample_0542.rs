struct Grid {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            grid: vec![vec![0; size]; size],
            size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                if self.grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                } else if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = self.grid[i][j];
                }
            }
        }
        self.grid = new_grid;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in max(0, x as isize - 1)..=min(self.size as isize - 1, x as isize + 1) {
            for j in max(0, y as isize - 1)..=min(self.size as isize - 1, y as isize + 1) {
                if (i, j) != (x as isize, y as isize) && self.grid[i as usize][j as usize] == 1 {
                    count += 1;
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
    fn new(grid: Grid) -> Self {
        Simulation { grid }
    }

    fn run(&mut self) {
        loop {
            self.grid.update();
        }
    }
}

fn main() {
    let size = 50;
    let grid = Grid::new(size);
    let mut simulation = Simulation::new(grid);
    simulation.run();
}