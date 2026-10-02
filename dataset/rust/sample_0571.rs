use rand::Rng;

struct Grid {
    width: usize,
    height: usize,
    grid: Vec<Vec<i32>>,
}

impl Grid {
    fn new(width: usize, height: usize) -> Self {
        Grid {
            width,
            height,
            grid: vec![vec![0; width]; height],
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.width]; self.height];
        for y in 0..self.height {
            for x in 0..self.width {
                let neighbors = self.count_neighbors(x, y);
                if self.grid[y][x] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        new_grid[y][x] = 0;
                    } else {
                        new_grid[y][x] = 1;
                    }
                } else if neighbors == 3 {
                    new_grid[y][x] = 1;
                }
            }
        }
        self.grid = new_grid;
    }

    fn count_neighbors(&self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = (x as i32 + i + self.width as i32) % self.width as i32;
                let ny = (y as i32 + j + self.height as i32) % self.height as i32;
                count += self.grid[ny as usize][nx as usize];
            }
        }
        count
    }

    fn display(&self) {
        for row in &self.grid {
            for &cell in row {
                print!("{}", if cell == 1 { 'O' } else { ' ' });
            }
            println!();
        }
    }
}

struct Simulation {
    grid: Grid,
}

impl Simulation {
    fn new(grid: Grid) -> Self {
        Simulation { grid }
    }

    fn run(&mut self) {
        loop {
            self.grid.update();
            self.grid.display();
            println!("{}", "-".repeat(self.grid.width));
        }
    }
}

fn main() {
    let width = 20;
    let height = 20;
    let mut grid = Grid::new(width, height);
    let mut rng = rand::thread_rng();
    for _ in 0..50 {
        let x = rng.gen_range(0..width);
        let y = rng.gen_range(0..height);
        grid.grid[y][x] = 1;
    }
    let mut simulation = Simulation::new(grid);
    simulation.run();
}