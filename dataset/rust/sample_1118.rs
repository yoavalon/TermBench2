struct Grid {
    size: usize,
    grid: Vec<Vec<usize>>,
}

impl Grid {
    fn new(size: usize) -> Self {
        Grid {
            size,
            grid: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.count_neighbors(i, j);
                if self.grid[i][j] == 0 {
                    new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
                } else {
                    new_grid[i][j] = if neighbors == 2 || neighbors == 3 { 1 } else { 0 };
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let ni = x as isize + i;
                let nj = y as isize + j;
                if ni >= 0 && ni < self.size as isize && nj >= 0 && nj < self.size as isize {
                    count += self.grid[ni as usize][nj as usize];
                }
            }
        }
        count
    }
}

fn display(grid: &Grid) {
    for row in &grid.grid {
        println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
    }
    println!();
}

fn main() {
    let size = 10;
    let mut grid = Grid::new(size);
    loop {
        display(&grid);
        grid.update();
    }
}