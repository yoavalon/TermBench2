struct Automata {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Automata {
    fn new(size: usize) -> Self {
        let grid = vec![vec![0; size]; size];
        Automata { grid, size }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
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

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = (x as isize + i) as usize;
                let ny = (y as isize + j) as usize;
                if nx < self.size && ny < self.size {
                    count += self.grid[nx][ny] as usize;
                }
            }
        }
        count
    }
}

fn main() {
    let size = 50;
    let mut automata = Automata::new(size);
    automata.grid[25][25] = 1;
    automata.grid[26][25] = 1;
    automata.grid[27][25] = 1;
    loop {
        automata.update();
    }
}