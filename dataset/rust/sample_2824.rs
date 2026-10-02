fn init_grid(rows: usize, cols: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![0; cols]; rows];
    grid[rows / 2][cols / 2] = 1;
    grid
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = [
                (i.checked_sub(1), j),
                (i.checked_add(1), j),
                (i, j.checked_sub(1)),
                (i, j.checked_add(1)),
            ]
            .iter()
            .filter_map(|&(x, y)| x.map(|x| y.map(|y| grid[x][y])))
            .sum::<i32>();
            new_grid[i][j] = if neighbors == 1 { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut grid = init_grid(10, 10);
    loop {
        grid = update_grid(&grid);
    }
}