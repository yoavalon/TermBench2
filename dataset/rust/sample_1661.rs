fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in 0.max(i as i32 - 1)..(rows as i32).min(i as i32 + 2) {
                for y in 0.max(j as i32 - 1)..(cols as i32).min(j as i32 + 2) {
                    if (x, y) != (i as i32, j as i32) {
                        neighbors += grid[x as usize][y as usize];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut initial_grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        initial_grid = update_grid(initial_grid);
        for row in initial_grid.iter() {
            println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<String>());
        }
        println!();
    }
}