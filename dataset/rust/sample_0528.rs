use std::vec::Vec;

struct Automaton {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Automaton {
    fn new(size: usize) -> Self {
        let grid = vec![vec![0; size]; size];
        Automaton { grid, size }
    }

    fn update(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.grid[(i + self.size - 1) % self.size][(j + self.size - 1) % self.size] +
                              self.grid[(i + self.size - 1) % self.size][j] +
                              self.grid[(i + self.size - 1) % self.size][(j + 1) % self.size] +
                              self.grid[i][(j + self.size - 1) % self.size] +
                              self.grid[i][(j + 1) % self.size] +
                              self.grid[(i + 1) % self.size][(j + self.size - 1) % self.size] +
                              self.grid[(i + 1) % self.size][j] +
                              self.grid[(i + 1) % self.size][(j + 1) % self.size];
                if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else if self.grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                }
            }
        }
        self.grid = new_grid;
    }
}

struct BoundaryHandler {
    automaton: Automaton,
}

impl BoundaryHandler {
    fn new(automaton: Automaton) -> Self {
        BoundaryHandler { automaton }
    }

    fn apply_boundary_conditions(&mut self) {
        for j in 0..self.automaton.size {
            self.automaton.grid[0][j] = 0;
            self.automaton.grid[self.automaton.size - 1][j] = 0;
        }
        for i in 0..self.automaton.size {
            self.automaton.grid[i][0] = 0;
            self.automaton.grid[i][self.automaton.size - 1] = 0;
        }
    }
}

fn main() {
    let size = 100;
    let mut automaton = Automaton::new(size);
    let mut boundary_handler = BoundaryHandler::new(automaton);
    automaton.grid[1][2] = 1;
    automaton.grid[2][3] = 1;
    automaton.grid[3][1] = 1;
    automaton.grid[3][2] = 1;
    automaton.grid[3][3] = 1;
    loop {
        boundary_handler.apply_boundary_conditions();
        automaton.update();
    }
}