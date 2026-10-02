struct FluidSimulator {
    grid: Vec<Vec<i32>>,
    rules: RuleSet,
}

impl FluidSimulator {
    fn new(grid_size: usize, rules: RuleSet) -> FluidSimulator {
        let grid = vec![vec![0; grid_size]; grid_size];
        FluidSimulator { grid, rules }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.grid.len()]; self.grid.len()];
        for i in 0..self.grid.len() {
            for j in 0..self.grid.len() {
                new_grid[i][j] = self.rules.apply(&self.grid, i, j);
            }
        }
        self.grid = new_grid;
    }

    fn display(&self) {
        for row in &self.grid {
            for &cell in row {
                print!("{} ", cell);
            }
            println!();
        }
        println!();
    }
}

struct RuleSet;

impl RuleSet {
    fn apply(&self, grid: &[Vec<i32>], x: usize, y: usize) -> i32 {
        let neighbors = self.count_neighbors(grid, x, y);
        if neighbors == 2 { 1 } else { 0 }
    }

    fn count_neighbors(&self, grid: &[Vec<i32>], x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in max(0, x as isize - 1) as usize..=min(grid.len(), x + 2) {
            for j in max(0, y as isize - 1) as usize..=min(grid.len(), y + 2) {
                if (i, j) != (x, y) && grid[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn main() {
    let grid_size = 10;
    let rules = RuleSet;
    let mut simulator = FluidSimulator::new(grid_size, rules);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    loop {
        simulator.display();
        simulator.update();
    }
}