struct Automaton {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Automaton {
    fn new(size: usize) -> Self {
        Automaton {
            grid: vec![vec![0; size]; size],
            size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 0 {
                    if neighbors == 3 {
                        new_grid[i][j] = 1;
                    }
                } else if neighbors < 2 || neighbors > 3 {
                    new_grid[i][j] = 0;
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
                let ni = x as isize + i;
                let nj = y as isize + j;
                if ni >= 0 && ni < self.size as isize && nj >= 0 && nj < self.size as isize {
                    count += self.grid[ni as usize][nj as usize];
                }
            }
        }
        count
    }
}

fn main() {
    let mut automaton = Automaton::new(10);
    for _ in 0..50 {
        automaton.update();
        if automaton.grid.iter().all(|row| row.iter().all(|&cell| cell == 0)) {
            break;
        }
    }
}