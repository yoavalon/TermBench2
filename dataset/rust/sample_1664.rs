use rand::Rng;

fn init_grid(size: usize) -> Vec<Vec<u8>> {
    let mut grid = vec![vec![0; size]; size];
    let mut rng = rand::thread_rng();
    for row in grid.iter_mut() {
        for cell in row.iter_mut() {
            *cell = rng.gen_range(0..2);
        }
    }
    grid
}

fn update_grid(grid: &Vec<Vec<u8>>) -> Vec<Vec<u8>> {
    let mut new_grid = grid.clone();
    let size = grid.len();
    for i in 1..size - 1 {
        for j in 1..size - 1 {
            let neighbors = [
                grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                grid[i][j - 1], grid[i][j + 1],
                grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1],
            ].iter().sum::<u8>() - grid[i][j];
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut grid = init_grid(size);
    loop {
        grid = update_grid(&grid);
        for row in &grid {
            println!("{}", row.iter().map(|&x| if x == 1 { '1' } else { '0' }).collect::<String>());
        }
        println!("{}", "-".repeat(40));
    }
}