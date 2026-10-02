use std::vec::Vec;

fn init_grid(size: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![0; size]; size];
    grid[size / 2][size / 2] = 1;
    grid
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = grid.clone();
    let rows = grid.len();
    let cols = grid[0].len();
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for di in -1..=1 {
                for dj in -1..=1 {
                    if di == 0 && dj == 0 {
                        continue;
                    }
                    let ni = (i as isize + di).max(0) as usize;
                    let ni = ni.min(rows - 1);
                    let nj = (j as isize + dj).max(0) as usize;
                    let nj = nj.min(cols - 1);
                    neighbors += grid[ni][nj];
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut grid = init_grid(size);
    let steps = 50;
    for _ in 0..steps {
        grid = update_grid(&grid);
    }
    for row in grid {
        println!("{:?}", row);
    }
}