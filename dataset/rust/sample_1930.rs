use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<f64>>, precision: usize) {
    let size = grid.len();
    let mut new_grid = vec![vec![0.0; size]; size];
    for i in 1..size - 1 {
        for j in 1..size - 1 {
            let mut sum = 0.0;
            for di in -1..=1 {
                for dj in -1..=1 {
                    sum += grid[i + di as usize][j + dj as usize];
                }
            }
            let avg = sum / 9.0;
            new_grid[i][j] = (avg * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32);
        }
    }
    *grid = new_grid;
}

fn run_simulation(steps: usize, precision: usize) -> Vec<Vec<f64>> {
    let grid_size = 10;
    let mut grid = vec![vec![0.0; grid_size]; grid_size];
    let mut rng = rand::thread_rng();
    for row in &mut grid {
        for cell in row {
            *cell = rng.gen();
        }
    }
    for _ in 0..steps {
        update_grid(&mut grid, precision);
    }
    grid
}

fn main() {
    let steps = 50;
    let precision = 3;
    let result = run_simulation(steps, precision);
    for row in result {
        println!("{:?}", row);
    }
}