struct CellularAutomaton {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl CellularAutomaton {
    fn new(size: usize) -> Self {
        let grid = vec![vec![0; size]; size];
        CellularAutomaton { grid, size }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self._count_neighbors(i, j);
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

    fn _count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in max(0, x as i32 - 1)..min(x as i32 + 2, self.size as i32) {
            for j in max(0, y as i32 - 1)..min(y as i32 + 2, self.size as i32) {
                if (i as usize, j as usize) != (x, y) {
                    count += self.grid[i as usize][j as usize];
                }
            }
        }
        count
    }
}

fn display(grid: &Vec<Vec<i32>>) {
    for row in grid {
        println!("{}", row.iter().map(|&cell| if cell == 1 { '█' } else { ' ' }).collect::<String>());
    }
}

fn main() {
    let size = 10;
    let mut automaton = CellularAutomaton::new(size);
    loop {
        display(&automaton.grid);
        automaton.update();
    }
}