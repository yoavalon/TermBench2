fn update_state(grid: &Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut new_grid = vec![vec![0.0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut neighbors = 0.0;
            for x in [-1, 0, 1] {
                for y in [-1, 0, 1] {
                    if x == 0 && y == 0 {
                        continue;
                    }
                    let ni = i as isize + x;
                    let nj = j as isize + y;
                    if ni >= 0 && ni < grid.len() as isize && nj >= 0 && nj < grid[0].len() as isize {
                        neighbors += grid[ni as usize][nj as usize];
                    }
                }
            }
            new_grid[i][j] = neighbors / 9.0;
        }
    }
    new_grid
}

fn run_simulation(steps: usize, size: usize) -> Vec<Vec<f64>> {
    let mut grid = vec![vec![0.0; size]; size];
    for i in 0..size {
        grid[i][i] = 1.0;
    }
    for _ in 0..steps {
        grid = update_state(&grid);
    }
    grid
}

fn main() {
    let result = run_simulation(10, 5);
    for row in result {
        println!("{:?}", row);
    }
}