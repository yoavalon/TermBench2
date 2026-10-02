fn simulate(n: usize) -> Vec<Vec<f64>> {
    let mut grid = vec![vec![0.0; n]; n];
    for i in 0..n {
        for j in 0..n {
            if i == 0 || j == 0 || i == n - 1 || j == n - 1 {
                grid[i][j] = 1.0;
            } else {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            }
        }
    }
    grid
}

fn main() {
    let _ = simulate(10);
}