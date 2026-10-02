struct Grid {
    size: usize,
    data: Vec<Vec<i32>>,
}

impl Grid {
    fn new(size: usize) -> Grid {
        Grid {
            size,
            data: vec![vec![0; size]; size],
        }
    }

    fn update(&mut self) {
        let mut new_data = vec![vec![0; self.size]; self.size];
        for i in 0..self.size {
            for j in 0..self.size {
                new_data[i][j] = self._calculate_next_state(i, j);
            }
        }
        self.data = new_data;
    }

    fn _calculate_next_state(&self, i: usize, j: usize) -> i32 {
        let neighbors = self._get_neighbors(i, j);
        let alive_count: i32 = neighbors.iter().sum();
        if self.data[i][j] == 1 {
            if alive_count == 2 || alive_count == 3 {
                1
            } else {
                0
            }
        } else {
            if alive_count == 3 {
                1
            } else {
                0
            }
        }
    }

    fn _get_neighbors(&self, i: usize, j: usize) -> Vec<i32> {
        let mut neighbors = Vec::new();
        for x in 0.max(i as i32 - 1) as usize..(self.size as i32).min(i as i32 + 2) as usize {
            for y in 0.max(j as i32 - 1) as usize..(self.size as i32).min(j as i32 + 2) as usize {
                if (x, y) != (i, j) {
                    neighbors.push(self.data[x][y]);
                }
            }
        }
        neighbors
    }
}

fn main() {
    let grid_size = 10;
    let mut grid = Grid::new(grid_size);
    let steps = 50;
    for _ in 0..steps {
        grid.update();
    }
}