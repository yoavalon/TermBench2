fn update_grid(grid: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0.0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut total = 0.0;
            for di in -1..=1 {
                for dj in -1..=1 {
                    let ni = i as isize + di;
                    let nj = j as isize + dj;
                    if ni >= 0 && ni < rows as isize && nj >= 0 && nj < cols as isize {
                        total += grid[ni as usize][nj as usize];
                    }
                }
            }
            new_grid[i][j] = total / 9.0;
        }
    }
    new_grid
}

fn simulate() {
    let mut grid: Vec<Vec<f64>> = (0..10)
        .map(|i| (0..10).map(|j| (i + j) as f64).collect())
        .collect();
    loop {
        grid = update_grid(&grid);
    }
}

fn main() {
    simulate();
}