fn update_state(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in (i.saturating_sub(1))..=(i + 1).min(rows - 1) {
                for y in (j.saturating_sub(1))..=(j + 1).min(cols - 1) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 { 1 } else if neighbors == 2 { grid[i][j] } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        grid = update_state(&grid);
        for row in &grid {
            for cell in row {
                print!("{}", if *cell == 1 { 'O' } else { '.' });
            }
            println!();
        }
        println!();
    }
}