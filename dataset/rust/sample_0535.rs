struct Cell {
    state: i32,
}

impl Cell {
    fn new(state: i32) -> Self {
        Cell { state }
    }

    fn update(&mut self, neighbors: &[&Cell]) {
        let alive_neighbors = neighbors.iter().filter(|&&n| n.state == 1).count();
        if self.state == 1 {
            if alive_neighbors < 2 || alive_neighbors > 3 {
                self.state = 0;
            }
        } else if alive_neighbors == 3 {
            self.state = 1;
        }
    }
}

struct Grid {
    width: usize,
    height: usize,
    grid: Vec<Vec<Cell>>,
}

impl Grid {
    fn new(width: usize, height: usize, initial_state: Vec<Vec<i32>>) -> Self {
        let grid = initial_state
            .into_iter()
            .map(|row| row.into_iter().map(Cell::new).collect())
            .collect();
        Grid { width, height, grid }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&Cell> {
        let mut neighbors = Vec::new();
        for dx in -1..=1 {
            for dy in -1..=1 {
                if dx == 0 && dy == 0 {
                    continue;
                }
                let nx = (x as isize + dx) as usize;
                let ny = (y as isize + dy) as usize;
                if nx < self.width && ny < self.height {
                    neighbors.push(&self.grid[nx][ny]);
                }
            }
        }
        neighbors
    }

    fn update(&mut self) {
        let mut new_grid = vec![vec![Cell::new(0); self.height]; self.width];
        for x in 0..self.width {
            for y in 0..self.height {
                let cell = &mut self.grid[x][y];
                let neighbors = self.get_neighbors(x, y);
                new_grid[x][y].update(&neighbors);
            }
        }
        self.grid = new_grid;
    }
}

fn main() {
    let width = 10;
    let height = 10;
    let initial_state = vec![
        vec![0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    let mut grid = Grid::new(width, height, initial_state);
    loop {
        grid.update();
    }
}