struct Cell {
    state: i32,
}

impl Cell {
    fn new(state: i32) -> Self {
        Cell { state }
    }

    fn update(&mut self, neighbors: &[&Cell]) {
        let live_neighbors = neighbors.iter().filter(|&&cell| cell.state == 1).count();
        if self.state == 1 {
            self.state = if live_neighbors == 2 || live_neighbors == 3 { 1 } else { 0 };
        } else {
            self.state = if live_neighbors == 3 { 1 } else { 0 };
        }
    }
}

struct Grid {
    width: usize,
    height: usize,
    grid: Vec<Vec<Cell>>,
}

impl Grid {
    fn new(width: usize, height: usize, initial_state: Option<&Vec<Vec<i32>>>) -> Self {
        let grid = (0..height)
            .map(|i| {
                (0..width)
                    .map(|j| {
                        if let Some(state) = initial_state {
                            Cell::new(state[i][j])
                        } else {
                            Cell::new(0)
                        }
                    })
                    .collect()
            })
            .collect();
        Grid { width, height, grid }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&Cell> {
        let directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1),
        ];
        directions
            .iter()
            .map(|&(dx, dy)| {
                let nx = x as isize + dx;
                let ny = y as isize + dy;
                if nx >= 0 && nx < self.width as isize && ny >= 0 && ny < self.height as isize {
                    Some(&self.grid[ny as usize][nx as usize])
                } else {
                    None
                }
            })
            .filter(|&cell| cell.is_some())
            .map(|cell| cell.unwrap())
            .collect()
    }

    fn update(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 0..self.height {
            for j in 0..self.width {
                let neighbors = self.get_neighbors(j, i);
                new_grid[i][j].update(&neighbors);
            }
        }
        self.grid = new_grid;
    }
}

fn main() {
    let initial_state = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    let mut grid = Grid::new(3, 3, Some(&initial_state));
    loop {
        grid.update();
    }
}