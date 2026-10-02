fn cellular_automata(x: usize, y: usize, steps: usize) {
    let mut grid = vec![vec![0; x]; y];
    for _ in 0..steps {
        let mut new_grid = grid.clone();
        for i in 0..y {
            for j in 0..x {
                let mut neighbors = 0;
                for di in -1..2 {
                    for dj in -1..2 {
                        if di != 0 || dj != 0 {
                            let ni = i as isize + di;
                            let nj = j as isize + dj;
                            if ni >= 0 && ni < y as isize && nj >= 0 && nj < x as isize {
                                neighbors += grid[ni as usize][nj as usize];
                            }
                        }
                    }
                }
                new_grid[i][j] = if neighbors == 3 || (neighbors == 2 && grid[i][j] == 1) { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
}

fn main() {
    cellular_automata(10, 10, 1000000);
}