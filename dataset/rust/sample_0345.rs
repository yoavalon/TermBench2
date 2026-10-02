fn cellular_automata() {
    let mut grid = vec![vec![0; 10]; 10];
    loop {
        for i in 1..9 {
            for j in 1..9 {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2;
            }
        }
        for i in 0..10 {
            grid[i][0] = grid[i][9];
            grid[i][9] = grid[i][0];
            grid[0][i] = grid[9][i];
            grid[9][i] = grid[0][i];
        }
    }
}

fn main() {
    cellular_automata();
}