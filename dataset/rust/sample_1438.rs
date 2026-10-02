struct CellularAutomaton {
    grid_size: usize,
    rule: std::collections::HashMap<&'static str, Vec<usize>>,
    grid: Vec<Vec<usize>>,
}

impl CellularAutomaton {
    fn new(grid_size: usize, rule: std::collections::HashMap<&'static str, Vec<usize>>) -> Self {
        let mut grid = vec![vec![0; grid_size]; grid_size];
        grid[grid_size / 2][grid_size / 2] = 1;
        CellularAutomaton {
            grid_size,
            rule,
            grid,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.grid_size]; self.grid_size];
        for i in 0..self.grid_size {
            for j in 0..self.grid_size {
                let neighbors = self.count_neighbors(i, j);
                new_grid[i][j] = self.apply_rule(self.grid[i][j], neighbors);
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in x.saturating_sub(1)..=x + 1 {
            for j in y.saturating_sub(1)..=y + 1 {
                if i < self.grid_size && j < self.grid_size && !(i == x && j == y) {
                    count += self.grid[i][j];
                }
            }
        }
        count
    }

    fn apply_rule(&self, cell: usize, neighbors: usize) -> usize {
        if cell == 1 && self.rule["survive"].contains(&neighbors) {
            1
        } else if cell == 0 && self.rule["birth"].contains(&neighbors) {
            1
        } else {
            0
        }
    }
}

fn main() {
    let size = 50;
    let mut rule = std::collections::HashMap::new();
    rule.insert("survive", vec![2, 3]);
    rule.insert("birth", vec![3]);
    let mut ca = CellularAutomaton::new(size, rule);
    for _ in 0..100 {
        ca.update();
    }
    for row in ca.grid {
        println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
    }
}