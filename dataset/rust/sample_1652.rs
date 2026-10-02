fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in i - 1..=i + 1 {
                for y in j - 1..=j + 1 {
                    if (0 <= x && x < rows && 0 <= y && y < cols) && (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 || (neighbors == 2 && grid[i][j] == 1) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(mut grid: Vec<Vec<i32>>) {
    loop {
        grid = update_grid(&grid);
    }
}

fn main() {
    let initial_grid = vec![
        vec![0, 0, 0, 0, 0],
        vec![0, 1, 1, 1, 0],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0],
    ];
    simulate(initial_grid);
}