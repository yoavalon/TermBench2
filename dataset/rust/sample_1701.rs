struct Automata {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl Automata {
    fn new(grid_size: usize) -> Self {
        Automata {
            grid: vec![vec![0; grid_size]; grid_size],
            size: grid_size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = (i.saturating_sub(1)..i + 2)
                    .flat_map(|x| (j.saturating_sub(1)..j + 2).map(move |y| (x, y)))
                    .filter(|&(x, y)| x < self.size && y < self.size && (x != i || y != j))
                    .map(|(x, y)| self.grid[x][y])
                    .sum::<i32>();
                if self.grid[i][j] == 1 {
                    new_grid[i][j] = if neighbors == 2 || neighbors == 3 { 1 } else { 0 };
                } else {
                    new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
                }
            }
        }
        self.grid = new_grid;
    }

    fn display(&self) {
        for row in &self.grid {
            for cell in row {
                print!("{}", if *cell == 1 { '#' } else { ' ' });
            }
            println!();
        }
        println!();
    }
}

fn initialize(grid: &mut Automata) {
    for i in 0..grid.size {
        for j in 0..grid.size {
            if i == j || i == grid.size - j - 1 {
                grid.grid[i][j] = 1;
            }
        }
    }
}

fn main() {
    let size = 10;
    let mut automata = Automata::new(size);
    initialize(&mut automata);
    loop {
        automata.display();
        automata.update();
    }
}