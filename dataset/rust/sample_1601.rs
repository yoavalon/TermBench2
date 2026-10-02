fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in 0.max(i as isize - 1)..(rows as isize).min(i as isize + 2) {
                for y in 0.max(j as isize - 1)..(cols as isize).min(j as isize + 2) {
                    if (x, y) != (i as isize, j as isize) && grid[x as usize][y as usize] == 1 {
                        neighbors += 1;
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 || (neighbors == 2 && grid[i][j] == 1) { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        grid = update_grid(grid);
        for row in &grid {
            for cell in row {
                print!("{} ", if *cell == 1 { 'O' } else { '.' });
            }
            println!();
        }
        println!();
    }
}