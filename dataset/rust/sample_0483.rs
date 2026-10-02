fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in 0.max(i - 1)..(i + 2).min(rows) {
                for y in 0.max(j - 1)..(j + 2).min(cols) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if grid[i][j] == 1 {
                new_grid[i][j] = if 2 <= neighbors && neighbors <= 3 { 1 } else { 0 };
            } else {
                new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
            }
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>) {
    let mut grid = grid;
    loop {
        grid = update_grid(&grid);
    }
}

fn main() {
    let initial_grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    simulate(initial_grid);
}