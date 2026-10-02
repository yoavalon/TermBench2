fn update_grid(grid: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0.0; cols]; rows];
    for i in 1..rows - 1 {
        for j in 1..cols - 1 {
            let avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            new_grid[i][j] = (grid[i][j] + avg) / 2.0;
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<f64>>, steps: usize) -> Vec<Vec<f64>> {
    let mut current_grid = grid;
    for _ in 0..steps {
        current_grid = update_grid(&current_grid);
    }
    current_grid
}

fn main() {
    let grid_size = 10;
    let steps = 5;
    let grid = vec![
        vec![
            if i == grid_size / 2 && j == grid_size / 2 { 1.0 } else { 0.0 }
            for j in 0..grid_size
        ]
        for i in 0..grid_size
    ];
    let result = simulate(grid, steps);
    for row in result {
        println!("{}", row.iter().map(|&x| format!("{:.2}", x)).collect::<Vec<_>>().join(" "));
    }
}