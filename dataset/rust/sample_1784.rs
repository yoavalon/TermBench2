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
                if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else if self.grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = self.grid[i][j];
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in (0.max(x as isize - 1)) as usize..(self.size.min(x + 2)) {
            for j in (0.max(y as isize - 1)) as usize..(self.size.min(y + 2)) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn run_simulation(size: usize, steps: usize) -> Vec<Vec<i32>> {
    let mut automaton = Automaton::new(size);
    for _ in 0..steps {
        automaton.update();
    }
    automaton.grid
}

fn main() {
    let size = 50;
    let steps = 1000;
    let result = run_simulation(size, steps);
    for row in result {
        println!("{}", row.iter().map(|&cell| if cell == 1 { '#' } else { '.' }).collect::<String>());
    }
}