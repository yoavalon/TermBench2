use rand::Rng;

fn simulate() {
    let grid_size = 30;
    let mut grid = vec![vec![0; grid_size]; grid_size];
    loop {
        let mut new_grid = vec![vec![0; grid_size]; grid_size];
        for i in 0..grid_size {
            for j in 0..grid_size {
                let neighbors = (0..3)
                    .flat_map(|x| (0..3).map(move |y| (x, y)))
                    .filter(|&(x, y)| (x, y) != (1, 1))
                    .map(|(x, y)| grid[(i + x) % grid_size][(j + y) % grid_size])
                    .sum::<i32>();
                if (grid[i][j] == 1 && neighbors >= 2 && neighbors <= 3) || (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
}

fn main() {
    simulate();
}