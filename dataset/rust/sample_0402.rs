fn update_cells(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in 0.max(i as i32 - 1)..=(i as i32 + 1).min(rows as i32 - 1) {
                for y in 0.max(j as i32 - 1)..=(j as i32 + 1).min(cols as i32 - 1) {
                    if (x, y) != (i as i32, j as i32) {
                        neighbors += grid[x as usize][y as usize];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 { 1 } else { grid[i][j] };
        }
    }
    new_grid
}

fn display_grid(grid: &Vec<Vec<i32>>) {
    for row in grid {
        for cell in row {
            print!("{}", if *cell == 1 { 'O' } else { '.' });
        }
        println!();
    }
}

fn main() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        display_grid(&grid);
        grid = update_cells(&grid);
    }
}