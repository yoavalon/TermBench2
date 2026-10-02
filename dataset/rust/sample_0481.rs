use std::vec::Vec;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    vec![vec![0; size]; size]
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = grid.clone();
    let rows = grid.len();
    let cols = grid[0].len();
    for i in 1..rows - 1 {
        for j in 1..cols - 1 {
            let neighbors = (i - 1..=i + 1).flat_map(|x| (j - 1..=j + 1).map(move |y| grid[x][y])).sum::<i32>();
            if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    new_grid
}

fn main() {
    let size = 50;
    let mut grid = initialize_grid(size);
    loop {
        grid = update_grid(&grid);
    }
}