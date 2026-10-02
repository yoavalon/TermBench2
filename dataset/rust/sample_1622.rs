use rand::Rng;

fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let neighbors = vec![
                grid[(i + size - 1) % size][(j + size - 1) % size],
                grid[(i + size - 1) % size][j],
                grid[(i + size - 1) % size][(j + 1) % size],
                grid[i][(j + size - 1) % size],
                grid[i][(j + 1) % size],
                grid[(i + 1) % size][(j + size - 1) % size],
                grid[(i + 1) % size][j],
                grid[(i + 1) % size][(j + 1) % size],
            ];
            let live_neighbors = neighbors.iter().sum();
            new_grid[i][j] = if grid[i][j] == 1 {
                if live_neighbors == 2 || live_neighbors == 3 { 1 } else { 0 }
            } else {
                if live_neighbors == 3 { 1 } else { 0 }
            };
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut rng = rand::thread_rng();
    let mut grid = vec![vec![if rng.gen_bool(0.5) { 1 } else { 0 }; size]; size];
    loop {
        grid = update_grid(grid);
        for row in &grid {
            for &cell in row {
                print!("{} ", cell);
            }
            println!();
        }
        println!();
    }
}