fn initialize_grid(size: usize) -> Vec<Vec<usize>> {
    let mut grid = vec![vec![0; size]; size];
    grid[size / 2][size / 2] = 1;
    grid
}

fn update_grid(grid: &Vec<Vec<usize>>) -> Vec<Vec<usize>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let neighbors = (0.max(i as isize - 1)..size.min(i as isize + 2))
                .flat_map(|x| (0.max(j as isize - 1)..size.min(j as isize + 2)).map(move |y| (x as usize, y as usize)))
                .filter(|&(x, y)| (x, y) != (i, j))
                .map(|(x, y)| grid[x][y])
                .sum::<usize>();
            new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut grid = initialize_grid(size);
    loop {
        grid = update_grid(&grid);
    }
}