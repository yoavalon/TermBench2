fn init_grid(size: usize) -> Vec<Vec<f64>> {
    vec![vec![0.0; size]; size]
}

fn update_grid(grid: &Vec<Vec<f64>>, diffusion_rate: f64) -> Vec<Vec<f64>> {
    let size = grid.len();
    let mut new_grid = init_grid(size);
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0.0;
            for di in [-1, 0, 1] {
                for dj in [-1, 0, 1] {
                    if di == 0 && dj == 0 {
                        continue;
                    }
                    let ni = i as isize + di;
                    let nj = j as isize + dj;
                    if ni >= 0 && ni < size as isize && nj >= 0 && nj < size as isize {
                        neighbors += grid[ni as usize][nj as usize];
                    }
                }
            }
            new_grid[i][j] = grid[i][j] + diffusion_rate * neighbors;
        }
    }
    new_grid
}

fn main() {
    let size = 100;
    let diffusion_rate = 0.01;
    let mut grid = init_grid(size);
    loop {
        grid = update_grid(&grid, diffusion_rate);
    }
}