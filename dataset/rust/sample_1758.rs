struct FluidSimulator {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl FluidSimulator {
    fn new(grid_size: usize) -> Self {
        FluidSimulator {
            grid: vec![vec![0; grid_size]; grid_size],
            size: grid_size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for x in 0..self.size {
            for y in 0..self.size {
                let neighbors = self.get_neighbors(x, y);
                if self.grid[x][y] == 1 {
                    if neighbors.iter().sum::<i32>() < 2 || neighbors.iter().sum::<i32>() > 3 {
                        new_grid[x][y] = 0;
                    } else {
                        new_grid[x][y] = 1;
                    }
                } else if neighbors.iter().sum::<i32>() == 3 {
                    new_grid[x][y] = 1;
                }
            }
        }
        self.grid = new_grid;
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<i32> {
        let mut neighbors = Vec::new();
        for dx in [-1, 0, 1].iter() {
            for dy in [-1, 0, 1].iter() {
                if *dx == 0 && *dy == 0 {
                    continue;
                }
                let nx = (x as isize + *dx) as usize;
                let ny = (y as isize + *dy) as usize;
                if nx < self.size && ny < self.size {
                    neighbors.push(self.grid[nx][ny]);
                }
            }
        }
        neighbors
    }

    fn display(&self) {
        for row in &self.grid {
            let line: String = row.iter().map(|&cell| if cell == 1 { '#' } else { ' ' }).collect();
            println!("{}", line);
        }
    }
}

fn main() {
    let mut simulator = FluidSimulator::new(10);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    simulator.grid[5][5] = 1;
    loop {
        simulator.display();
        simulator.update();
    }
}