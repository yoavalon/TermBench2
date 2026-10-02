fn fluid_dynamics(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut next_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let neighbors: i32 = (max(0, i - 1)..min(size, i + 2))
                .flat_map(|x| (max(0, j - 1)..min(size, j + 2)).map(move |y| grid[x][y]))
                .sum();
            next_grid[i][j] = if neighbors > 4 { 1 } else { 0 };
        }
    }
    fluid_dynamics(next_grid)
}

fn main() {
    let mut grid = vec![vec![0; 10]; 10];
    grid[5][5] = 1;
    fluid_dynamics(grid);
}