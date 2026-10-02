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
                let neighbors = self._count_neighbors(i, j);
                if self.grid[i][j] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if neighbors == 3 {
                    new_grid[i][j] = 1;
                }
            }
        }
        self.grid = new_grid;
    }

    fn _count_neighbors(&self, x: usize, y: usize) -> usize {
        let mut count = 0;
        for i in max(0, x as isize - 1)..=min((x + 1) as isize, self.size as isize) {
            for j in max(0, y as isize - 1)..=min((y + 1) as isize, self.size as isize) {
                if (i != x as isize || j != y as isize) && self.grid[i as usize][j as usize] == 1 {
                    count += 1;
                }
            }
        }
        count
    }
}

fn main() {
    let size = 10;
    let mut ca = CellularAutomata::new(size);
    for _ in 0..100 {
        ca.update();
    }
    for row in ca.grid {
        println!("{}", row.iter().map(|&cell| if cell == 1 { '*' } else { ' ' }).collect::<String>());
    }
}