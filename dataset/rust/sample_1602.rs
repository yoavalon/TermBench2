fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = (max(0, i - 1)..min(rows, i + 2)).flat_map(|x| {
                (max(0, j - 1)..min(cols, j + 2)).filter_map(|y| {
                    if (x, y) != (i, j) { Some(grid[x][y]) } else { None }
                })
            }).sum::<i32>();
            new_grid[i][j] = if neighbors == 3 { 1 } else if grid[i][j] == 1 && neighbors == 2 { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>) {
    loop {
        let grid = update_grid(grid);
    }
}

fn main() {
    let initial_grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    simulate(initial_grid);
}