fn initialize_grid(rows: usize, cols: usize) -> Vec<Vec<usize>> {
    vec![vec![0; cols]; rows]
}

fn update_grid(grid: Vec<Vec<usize>>) -> Vec<Vec<usize>> {
    let mut new_grid = grid.clone();
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut neighbors = 0;
            for x in i.saturating_sub(1)..=i.min(grid.len() - 1) {
                for y in j.saturating_sub(1)..=j.min(grid[0].len() - 1) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 {
                1
            } else if neighbors < 2 || neighbors > 3 {
                0
            } else {
                grid[i][j]
            };
        }
    }
    new_grid
}

fn main() {
    let rows = 50;
    let cols = 50;
    let mut grid = initialize_grid(rows, cols);
    loop {
        grid = update_grid(grid);
    }
}