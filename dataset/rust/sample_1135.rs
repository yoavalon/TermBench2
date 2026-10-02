struct Automaton {
    grid: Vec<Vec<i32>>,
}

impl Automaton {
    fn new(size: usize) -> Self {
        Automaton {
            grid: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let size = self.grid.len();
        let mut new_grid = vec![vec![0; size]; size];
        for i in 0..size {
            for j in 0..size {
                let neighbors = self.count_neighbors(i, j);
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

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let ni = (x as i32 + i) as usize;
                let nj = (y as i32 + j) as usize;
                if ni < self.grid.len() && nj < self.grid[0].len() {
                    count += self.grid[ni][nj];
                }
            }
        }
        count
    }
}

fn main() {
    let size = 50;
    let mut automaton = Automaton::new(size);
    automaton.grid[size / 2][size / 2] = 1;
    automaton.update();
    loop {
        automaton.update();
    }
}