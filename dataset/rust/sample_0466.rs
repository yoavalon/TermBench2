fn update_cell(grid: &Vec<Vec<i32>>, i: usize, j: usize, size: usize) -> bool {
    let mut neighbors = 0;
    for x in i.saturating_sub(1)..=i.min(size - 1) + 1 {
        for y in j.saturating_sub(1)..=j.min(size - 1) + 1 {
            if (x != i || y != j) && x < size && y < size {
                neighbors += grid[x][y];
            }
        }
    }
    neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
}

fn step(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            new_grid[i][j] = update_cell(grid, i, j, size) as i32;
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut grid = vec![vec![0; size]; size];
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][1] = 1;
    loop {
        grid = step(&grid);
    }
}