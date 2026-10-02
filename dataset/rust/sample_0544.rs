struct Grid {
    size: usize,
    state: Vec<Vec<i32>>,
}

impl Grid {
    fn new(size: usize) -> Grid {
        Grid {
            size,
            state: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let mut new_state = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                if self.state[i][j] == 0 && neighbors == 3 {
                    new_state[i][j] = 1;
                } else if self.state[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_state[i][j] = 0;
                } else {
                    new_state[i][j] = self.state[i][j];
                }
            }
        }
        self.state = new_state;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in 0.max(x as i32 - 1)..(x as i32 + 2).min(self.size as i32) {
            for j in 0.max(y as i32 - 1)..(y as i32 + 2).min(self.size as i32) {
                if (i, j) != (x as i32, y as i32) && self.state[i as usize][j as usize] == 1 {
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
            print!("{}", if cell == 1 { '*' } else { ' ' });
        }
        println!();
    }
    println!();
}

fn main() {
    let size = 10;
    let mut grid = Grid::new(size);
    for i in 0..size {
        for j in 0..size {
            if i % 2 == 0 && j % 2 == 0 {
                grid.state[i][j] = 1;
            }
        }
    }
    loop {
        display(&grid);
        grid.update();
    }
}