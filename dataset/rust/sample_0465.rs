fn initialize_grid(size: usize) -> Vec<Vec<usize>> {
    let mut grid = vec![vec![0; size]; size];
    grid[size / 2][size / 2] = 1;
    grid
}

fn update_grid(grid: &Vec<Vec<usize>>) -> Vec<Vec<usize>> {
    let mut new_grid = vec![vec![0; grid.len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid.len() {
            let mut neighbors = 0;
            for x in 0.max(i as isize - 1) as usize..(grid.len() as isize).min(i as isize + 2) as usize {
                for y in 0.max(j as isize - 1) as usize..(grid.len() as isize).min(j as isize + 2) as usize {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let grid_size = 10;
    let mut grid = initialize_grid(grid_size);
    loop {
        grid = update_grid(&grid);
    }
}