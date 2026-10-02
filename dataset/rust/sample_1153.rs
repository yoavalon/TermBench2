use rand::Rng;

struct CellAutomata {
    grid_size: usize,
    grid: Vec<Vec<i32>>,
}

impl CellAutomata {
    fn new(grid_size: usize) -> Self {
        CellAutomata {
            grid_size,
            grid: Self::initialize_grid(grid_size),
        }
    }

    fn initialize_grid(grid_size: usize) -> Vec<Vec<i32>> {
        let mut grid = vec![vec![0; grid_size]; grid_size];
        let mut rng = rand::thread_rng();
        for i in 0..grid_size {
            for j in 0..grid_size {
                grid[i][j] = rng.gen_range(0..2);
            }
        }
        grid
    }

    fn update_grid(&mut self) {
        let mut new_grid = vec![vec![0; self.grid_size]; self.grid_size];
        for i in 0..self.grid_size {
            for j in 0..self.grid_size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 1 {
                    if neighbors == 2 || neighbors == 3 {
                        new_grid[i][j] = 1;
                    }
                } else if neighbors == 3 {
                    new_grid[i][j] = 1;
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in -1..2 {
            for j in -1..2 {
                if i == 0 && j == 0 {
                    continue;
                }
                let ni = (x as isize + i + self.grid_size as isize) % self.grid_size as isize;
                let nj = (y as isize + j + self.grid_size as isize) % self.grid_size as isize;
                count += self.grid[ni as usize][nj as usize];
            }
        }
        count
    }
}

fn main() {
    let size = 50;
    let mut automata = CellAutomata::new(size);
    loop {
        automata.update_grid();
    }
}