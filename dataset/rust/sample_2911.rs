use rand::Rng;

struct AutomatonCell {
    state: i32,
}

impl AutomatonCell {
    fn new(state: i32) -> Self {
        AutomatonCell { state }
    }

    fn update_state(&mut self, neighbors: &[&AutomatonCell]) {
        let alive_neighbors = neighbors.iter().filter(|&&cell| cell.state == 1).count();
        if self.state == 1 {
            if alive_neighbors < 2 || alive_neighbors > 3 {
                self.state = 0;
            }
        } else if alive_neighbors == 3 {
            self.state = 1;
        }
    }
}

struct AutomatonGrid {
    grid: Vec<Vec<AutomatonCell>>,
}

impl AutomatonGrid {
    fn new(size: usize) -> Self {
        let mut grid = Vec::new();
        let mut rng = rand::thread_rng();
        for _ in 0..size {
            let row: Vec<AutomatonCell> = (0..size).map(|_| AutomatonCell::new(rng.gen_range(0..=1))).collect();
            grid.push(row);
        }
        AutomatonGrid { grid }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&AutomatonCell> {
        let size = self.grid.len();
        let mut neighbors = Vec::new();
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = (x as i32 + i) as usize;
                let ny = (y as i32 + j) as usize;
                if nx < size && ny < size {
                    neighbors.push(&self.grid[nx][ny]);
                }
            }
        }
        neighbors
    }

    fn update_grid(&mut self) {
        let size = self.grid.len();
        let mut new_grid = vec![vec![AutomatonCell::new(0); size]; size];
        for x in 0..size {
            for y in 0..size {
                let neighbors = self.get_neighbors(x, y);
                new_grid[x][y].update_state(&neighbors);
            }
        }
        self.grid = new_grid;
    }
}

fn simulate() {
    let size = 50;
    let mut grid = AutomatonGrid::new(size);
    loop {
        grid.update_grid();
    }
}

fn main() {
    simulate();
}