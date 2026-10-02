fn update_grid(grid: Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut new_grid = vec![vec![0.0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            if i > 0 && j > 0 && i < grid.len() - 1 && j < grid[0].len() - 1 {
                new_grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    new_grid
}

fn simulate(n: usize, size: usize) -> Vec<Vec<f64>> {
    let mut grid = vec![vec![0.0; size]; size];
    for i in 0..size {
        for j in 0..size {
            grid[i][j] = if i == size / 2 && j == size / 2 { 1.0 } else { 0.0 };
        }
    }
    for _ in 0..n {
        grid = update_grid(grid);
    }
    grid
}

fn main() {
    let result = simulate(10, 5);
    for row in result {
        println!("{:?}", row);
    }
}