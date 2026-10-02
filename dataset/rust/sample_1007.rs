fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in (0.max(i - 1))..(rows.min(i + 2)) {
                for y in (0.max(j - 1))..(cols.min(j + 2)) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if (2 <= neighbors && neighbors <= 3) || (grid[i][j] == 0 && neighbors == 3) { 1 } else { 0 };
        }
    }
    new_grid
}

fn run_simulation(grid: Vec<Vec<i32>>) {
    let mut current_grid = grid;
    loop {
        current_grid = update_grid(&current_grid);
    }
}

fn main() {
    let initial_grid = vec![vec![0, 1, 0], vec![1, 1, 1], vec![0, 1, 0]];
    run_simulation(initial_grid);
}