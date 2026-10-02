fn cellular_automata(width: usize, height: usize) {
    let mut grid = vec![vec![0; width]; height];
    loop {
        let mut new_grid = grid.clone();
        for i in 1..height - 1 {
            for j in 1..width - 1 {
                let neighbors = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                               grid[i][j - 1] + grid[i][j + 1] +
                               grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
                if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else if grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
}

fn main() {
    cellular_automata(50, 50);
}