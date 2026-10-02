use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<u8>>) {
    let grid_size = grid.len();
    let mut new_grid = vec![vec![0; grid_size]; grid_size];
    for i in 1..grid_size - 1 {
        for j in 1..grid_size - 1 {
            let mut neighbors = 0;
            for ni in i - 1..=i + 1 {
                for nj in j - 1..=j + 1 {
                    neighbors += grid[ni][nj];
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

fn simulate() {
    let grid_size = 50;
    let mut grid = vec![vec![0; grid_size]; grid_size];
    let mut rng = rand::thread_rng();
    for i in 0..grid_size {
        for j in 0..grid_size {
            grid[i][j] = if rng.gen_bool(0.5) { 1 } else { 0 };
        }
    }
    loop {
        update_grid(&mut grid);
    }
}

fn main() {
    simulate();
}