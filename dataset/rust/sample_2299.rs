fn update_state(grid: Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0.0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = vec![(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)];
            let value: f64 = neighbors.iter()
                .filter(|&&(x, y)| x >= 0 && x < rows && y >= 0 && y < cols)
                .map(|&(x, y)| grid[x][y])
                .sum();
            new_grid[i][j] = value / 4.0;
        }
    }
    new_grid
}

fn simulate(mut grid: Vec<Vec<f64>>) {
    loop {
        grid = update_state(grid);
    }
}

fn main() {
    let grid_size = 10;
    let initial_grid: Vec<Vec<f64>> = (0..grid_size)
        .map(|i| (0..grid_size).map(|j| (i * j) as f64).collect())
        .collect();
    simulate(initial_grid);
}