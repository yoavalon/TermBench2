struct FluidGrid {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl FluidGrid {
    fn new(size: usize) -> Self {
        FluidGrid {
            grid: vec![vec![0; size]; size],
            size,
        }
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                new_grid[i][j] = self.calculate_next_state(i, j);
            }
        }
        self.grid = new_grid;
    }

    fn calculate_next_state(&self, x: usize, y: usize) -> i32 {
        let neighbors = self.get_neighbors(x, y);
        let count = neighbors.iter().sum::<i32>();
        if self.grid[x][y] == 0 {
            if count > 2 { 1 } else { 0 }
        } else {
            if count == 2 || count == 3 { 1 } else { 0 }
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<i32> {
        let directions = vec![(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)];
        let mut neighbors = Vec::new();
        for (dx, dy) in directions {
            let nx = x as isize + dx;
            let ny = y as isize + dy;
            if nx >= 0 && nx < self.size as isize && ny >= 0 && ny < self.size as isize {
                neighbors.push(self.grid[nx as usize][ny as usize]);
            } else {
                neighbors.push(0);
            }
        }
        neighbors
    }
}

fn main() {
    let size = 10;
    let mut grid = FluidGrid::new(size);
    loop {
        grid.update();
    }
}