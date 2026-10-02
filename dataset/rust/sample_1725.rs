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
                } else {
                    new_grid[i][j] = 1;
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
                let ni = x as i32 + i;
                let nj = y as i32 + j;
                if ni >= 0 && ni < self.size as i32 && nj >= 0 && nj < self.size as i32 {
                    count += self.grid[ni as usize][nj as usize];
                }
            }
        }
        count
    }
}

fn display(grid: &Vec<Vec<i32>>) {
    for row in grid {
        let mut line = String::new();
        for &cell in row {
            line.push(if cell == 1 { '#' } else { ' ' });
        }
        println!("{}", line);
    }
}

fn main() {
    let size = 10;
    let mut automaton = Automaton::new(size);
    automaton.grid[5][5] = 1;
    automaton.grid[5][6] = 1;
    automaton.grid[6][5] = 1;
    automaton.grid[6][6] = 1;
    loop {
        display(&automaton.grid);
        automaton.update();
    }
}