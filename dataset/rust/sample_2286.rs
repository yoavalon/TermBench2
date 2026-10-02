use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = grid.clone();

    for i in 1..rows - 1 {
        for j in 1..cols - 1 {
            let neighbors = (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1]
                            + grid[i][j - 1] + grid[i][j + 1]
                            + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1]);
            if grid[i][j] == 1 {
                new_grid[i][j] = if neighbors == 2 || neighbors == 3 { 1 } else { 0 };
            } else {
                new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
            }
        }
    }

    *grid = new_grid;
}

fn main() {
    let grid_size = 50;
    let mut grid = vec![vec![0; grid_size]; grid_size];
    let mut rng = rand::thread_rng();

    for row in &mut grid {
        for cell in row {
            *cell = rng.gen_range(0..2);
        }
    }

    loop {
        update_grid(&mut grid);
    }
}