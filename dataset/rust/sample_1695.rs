use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in 0.max(i as i32 - 1)..=(i as i32 + 1).min(rows as i32 - 1) {
                for y in 0.max(j as i32 - 1)..=(j as i32 + 1).min(cols as i32 - 1) {
                    neighbors += grid[x as usize][y as usize];
                }
            }
            neighbors -= grid[i][j];
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    *grid = new_grid;
}

fn run_simulation() {
    let grid_size = 50;
    let mut grid = vec![vec![0; grid_size]; grid_size];
    let mut rng = rand::thread_rng();
    for i in 0..grid_size {
        for j in 0..grid_size {
            grid[i][j] = rng.gen_range(0..2);
        }
    }
    loop {
        update_grid(&mut grid);
    }
}

fn main() {
    run_simulation();
}