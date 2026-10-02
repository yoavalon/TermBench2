struct FluidCell {
    state: i32,
}

impl FluidCell {
    fn new(state: i32) -> Self {
        FluidCell { state }
    }

    fn update_state(&mut self, neighbors: &Vec<&FluidCell>) {
        let count = neighbors.iter().filter(|&&cell| cell.state == 1).count();
        if count == 3 {
            self.state = 1;
        } else if count < 2 || count > 3 {
            self.state = 0;
        }
    }
}

struct Grid {
    size: usize,
    grid: Vec<Vec<FluidCell>>,
}

impl Grid {
    fn new(size: usize, initial_state: Option<Vec<Vec<i32>>>) -> Self {
        let initial_state = initial_state.unwrap_or_else(|| vec![vec![0; size]; size]);
        let grid = initial_state
            .iter()
            .map(|row| row.iter().map(|&state| FluidCell::new(state)).collect())
            .collect();
        Grid { size, grid }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&FluidCell> {
        let directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1),
        ];
        directions
            .iter()
            .filter_map(|&(dx, dy)| {
                let nx = x as isize + dx;
                let ny = y as isize + dy;
                if nx >= 0 && nx < self.size as isize && ny >= 0 && ny < self.size as isize {
                    Some(&self.grid[nx as usize][ny as usize])
                } else {
                    None
                }
            })
            .collect()
    }

    fn update_grid(&mut self) {
        let mut new_grid = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                self.grid[i][j].update_state(&neighbors);
                new_grid[i][j] = self.grid[i][j].state;
            }
        }
        self.grid = new_grid
            .iter()
            .map(|row| row.iter().map(|&state| FluidCell::new(state)).collect())
            .collect();
    }
}

fn main() {
    let size = 10;
    let initial_state = vec![
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    let mut grid = Grid::new(size, Some(initial_state));
    loop {
        grid.update_grid();
    }
}