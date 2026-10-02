use rand::Rng;

fn initialize_grid(size: usize) -> Vec<Vec<f64>> {
    let mut grid = vec![vec![0.0; size]; size];
    let mut rng = rand::thread_rng();
    for i in 0..size {
        for j in 0..size {
            grid[i][j] = rng.gen_range(0.0..1.0);
        }
    }
    grid
}

fn evolve(grid: &mut Vec<Vec<f64>>, steps: usize) {
    let size = grid.len();
    for _ in 0..steps {
        let mut new_grid = grid.clone();
        for i in 0..size {
            for j in 0..size {
                let top = grid[(i + size - 1) % size][j];
                let bottom = grid[(i + 1) % size][j];
                let left = grid[i][(j + size - 1) % size];
                let right = grid[i][(j + 1) % size];
                new_grid[i][j] = top + bottom + left + right;
                new_grid[i][j] = new_grid[i][j].clamp(0.0, 1.0);
            }
        }
        *grid = new_grid;
    }
}

fn main() {
    let size = 100;
    let mut grid = initialize_grid(size);
    loop {
        evolve(&mut grid, 10);
        for row in &grid {
            println!("{:?}", row);
        }
    }
}