struct Automaton {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Automaton {
    fn new(grid_size: usize) -> Self {
        let grid = vec![vec![0; grid_size]; grid_size];
        Automaton { grid, size: grid_size }
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
        for i in max(0, x as isize - 1)..min(self.size as isize, x as isize + 2) as usize {
            for j in max(0, y as isize - 1)..min(self.size as isize, y as isize + 2) as usize {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn simulate(automaton: &mut Automaton, steps: usize) {
    for _ in 0..steps {
        automaton.update();
    }
}

fn main() {
    let grid_size = 10;
    let steps = 50;
    let mut automaton = Automaton::new(grid_size);
    simulate(&mut automaton, steps);
}