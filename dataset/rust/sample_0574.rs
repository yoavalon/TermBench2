struct Cell {
    state: i32,
}

impl Cell {
    fn new(state: i32) -> Cell {
        Cell { state }
    }

    fn update(&mut self, neighbors: Vec<&Cell>) {
        let live_neighbors = neighbors.iter().filter(|&&cell| cell.state == 1).count() as i32;
        if self.state == 1 && (live_neighbors < 2 || live_neighbors > 3) {
            self.state = 0;
        } else if self.state == 0 && live_neighbors == 3 {
            self.state = 1;
        }
    }
}

struct Grid {
    size: usize,
    cells: Vec<Vec<Cell>>,
}

impl Grid {
    fn new(size: usize, initial_state: Vec<Vec<i32>>) -> Grid {
        Grid {
            size,
            cells: initial_state
                .into_iter()
                .map(|row| row.into_iter().map(Cell::new).collect())
                .collect(),
        }
    }

    fn get_neighbors(&self, x: usize, y: usize) -> Vec<&Cell> {
        let mut neighbors = Vec::new();
        for i in -1..=1 {
            for j in -1..=1 {
                if i == 0 && j == 0 {
                    continue;
                }
                let nx = (x as isize + i) as usize;
                let ny = (y as isize + j) as usize;
                if nx < self.size && ny < self.size {
                    neighbors.push(&self.cells[nx][ny]);
                } else {
                    neighbors.push(&Cell::new(0));
                }
            }
        }
        neighbors
    }

    fn update(&mut self) {
        let mut new_cells = self.cells
            .iter()
            .map(|row| row.iter().map(|cell| Cell::new(cell.state)).collect())
            .collect();
        for i in 0..self.size {
            for j in 0..self.size {
                let neighbors = self.get_neighbors(i, j);
                new_cells[i][j].update(neighbors);
            }
        }
        self.cells = new_cells;
    }
}

fn main() {
    let size = 10;
    let mut initial_state = vec![vec![0; size]; size];
    initial_state[4][4] = 1;
    initial_state[4][5] = 1;
    initial_state[5][4] = 1;
    initial_state[5][5] = 1;
    let mut grid = Grid::new(size, initial_state);
    loop {
        grid.update();
    }
}