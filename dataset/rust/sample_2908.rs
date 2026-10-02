struct Automata {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Automata {
    fn new(size: usize) -> Self {
        Automata {
            grid: vec![vec![0; size]; size],
            size,
        }
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

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = x as isize + i;
                let ny = y as isize + j;
                if nx >= 0 && nx < self.size as isize && ny >= 0 && ny < self.size as isize {
                    count += self.grid[nx as usize][ny as usize];
                }
            }
        }
        count
    }

    fn display(&self) {
        for row in &self.grid {
            let line: String = row.iter().map(|&cell| if cell == 1 { '#' } else { ' ' }).collect();
            println!("{}", line);
        }
    }
}

fn main() {
    let size = 20;
    let mut automata = Automata::new(size);
    loop {
        automata.display();
        automata.update();
    }
}