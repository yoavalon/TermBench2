fn simulate_flow(n: usize) {
    let mut grid = vec![vec![0.0; n]; n];
    loop {
        let mut new_grid = vec![vec![0.0; n]; n];
        for i in 0..n {
            for j in 0..n {
                new_grid[i][j] = (grid[i][(j as isize - 1 + n as isize) % n as isize] +
                                 grid[i][(j as isize + 1) % n as isize] +
                                 grid[(i as isize - 1 + n as isize) % n as isize][j] +
                                 grid[(i as isize + 1) % n as isize][j]) / 4.0;
            }
        }
        grid = new_grid;
    }
}

fn main() {
    simulate_flow(10);
}