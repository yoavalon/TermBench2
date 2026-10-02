use rand::Rng;

fn update_state(grid: &mut Vec<Vec<i32>>) {
    let size = grid.len();
    let mut new_grid = grid.clone();
    for i in 1..size - 1 {
        for j in 1..size - 1 {
            let neighbors = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                           grid[i][j - 1] + grid[i][j + 1] +
                           grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    *grid = new_grid;
}

fn main() {
    let size = 50;
    let mut rng = rand::thread_rng();
    let mut grid = vec![vec![0; size]; size];
    for row in &mut grid {
        for cell in row {
            *cell = rng.gen_range(0..2);
        }
    }
    loop {
        update_state(&mut grid);
    }
}