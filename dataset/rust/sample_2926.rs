struct CellularAutomata {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl CellularAutomata {
    fn new(size: usize) -> Self {
        CellularAutomata {
            grid: vec![vec![0; size]; size],
            size,
        }
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
        for i in 0.max(x as isize - 1) as usize..=(x + 1).min(self.size - 1) {
            for j in 0.max(y as isize - 1) as usize..=(y + 1).min(self.size - 1) {
                if (i, j) != (x, y) && self.grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

struct Simulation {
    automata: CellularAutomata,
    size: usize,
}

impl Simulation {
    fn new(size: usize) -> Self {
        Simulation {
            automata: CellularAutomata::new(size),
            size,
        }
    }

    fn run(&mut self) {
        loop {
            self.automata.update();
        }
    }
}

fn main() {
    let mut simulation = Simulation::new(10);
    simulation.run();
}