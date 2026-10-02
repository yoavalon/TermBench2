struct Grid {
    size: usize,
    state: Vec<Vec<usize>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            size,
            state: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let mut new_state = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.state[i][j] == 0 {
                    if neighbors == 3 {
                        new_state[i][j] = 1;
                    }
                } else if neighbors == 2 || neighbors == 3 {
                    new_state[i][j] = 1;
                }
            }
        }
        self.state = new_state;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in max(0, x - 1)..min(self.size, x + 2) {
            for j in max(0, y - 1)..min(self.size, y + 2) {
                if (i, j) != (x, y) && self.state[i][j] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn display(grid: &Grid) {
    for row in &grid.state {
        for &cell in row {
            print!("{}", if cell == 1 { 'O' } else { '.' });
        }
        println!();
    }
    println!();
}

fn main() {
    let size = 50;
    let mut grid = Grid::new(size);
    for i in 0..size {
        for j in 0..size {
            grid.state[i][j] = if (i + j) % 2 == 0 { 1 } else { 0 };
        }
    }
    loop {
        display(&grid);
        grid.update();
    }
}