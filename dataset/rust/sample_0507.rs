extern crate rand;

use rand::Rng;

struct Grid {
    size: usize,
    grid: Vec<Vec<i32>>,
}

impl Grid {
    fn new(size: usize) -> Grid {
        let mut grid = Vec::with_capacity(size);
        for _ in 0..size {
            let mut row = Vec::with_capacity(size);
            for _ in 0..size {
                row.push(rand::thread_rng().gen_range(0..2));
            }
            grid.push(row);
        }
        Grid { size, grid }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let state = self.grid[i][j];
                let neighbors = self.count_neighbors(i, j);
                if state == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                } else if state == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = state;
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in (0.max(x as i32 - 1)) as usize..(self.size.min(x + 2)) {
            for j in (0.max(y as i32 - 1)) as usize..(self.size.min(y + 2)) {
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
    fn new(grid: Grid) -> Simulation {
        Simulation { grid }
    }

    fn run(&mut self) {
        loop {
            self.grid.update();
            self.display();
        }
    }

    fn display(&self) {
        for row in &self.grid.grid {
            for &cell in row {
                print!("{}", if cell == 1 { '#' } else { ' ' });
            }
            println!("-");
        }
    }
}

fn main() {
    let size = 50;
    let grid = Grid::new(size);
    let mut simulation = Simulation::new(grid);
    simulation.run();
}