fn simulate() {
    let mut grid = vec![vec![0; 50]; 50];
    loop {
        let mut new_grid = vec![vec![0; 50]; 50];
        for i in 1..49 {
            for j in 1..49 {
                let neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1];
                new_grid[i][j] = if neighbors == 2 { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
}

fn main() {
    simulate();
}