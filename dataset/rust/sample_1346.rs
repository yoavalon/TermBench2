use rand::Rng;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    let mut rng = rand::thread_rng();
    (0..size).map(|_| (0..size).map(|_| rng.gen_range(0..2)).collect()).collect()
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for x in i.saturating_sub(1)..=(i + 1).min(size - 1) {
                for y in j.saturating_sub(1)..=(j + 1).min(size - 1) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    new_grid
}

fn main() {
    let size = 5;
    let mut grid = initialize_grid(size);
    for _ in 0..10 {
        grid = update_grid(&grid);
    }
    for row in grid {
        println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
    }
}