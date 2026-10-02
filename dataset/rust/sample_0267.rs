struct Grid {
    size: usize,
    grid: Vec<Vec<i32>>,
    boundary: String,
}

impl Grid {
    fn new(size: usize, boundary: String) -> Self {
        Grid {
            size,
            grid: vec![vec![0; size]; size],
            boundary,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.boundary_condition(i, j);
                new_grid[i][j] = self.apply_rules(&neighbors, self.grid[i][j]);
            }
        }
        self.grid = new_grid;
    }

    fn boundary_condition(&self, x: usize, y: usize) -> Vec<i32> {
        let mut neighbors = Vec::new();
        for dx in -1..=1 {
            for dy in -1..=1 {
                if dx == 0 && dy == 0 {
                    continue;
                }
                let nx = (x as isize + dx) as usize;
                let ny = (y as isize + dy) as usize;
                if self.boundary == "fixed" {
                    if nx < self.size && ny < self.size {
                        neighbors.push(self.grid[nx][ny]);
                    }
                } else if self.boundary == "periodic" {
                    neighbors.push(self.grid[(nx + self.size) % self.size][(ny + self.size) % self.size]);
                }
            }
        }
        neighbors
    }

    fn apply_rules(&self, neighbors: &[i32], current: i32) -> i32 {
        let count = neighbors.iter().sum::<i32>();
        if current == 1 {
            if count < 2 || count > 3 {
                return 0;
            }
            return 1;
        } else {
            if count == 3 {
                return 1;
            }
            return 0;
        }
    }
}

fn main() {
    let size = 10;
    let boundary = String::from("periodic");
    let mut grid = Grid::new(size, boundary);
    let steps = 50;
    for _ in 0..steps {
        grid.update();
    }
}