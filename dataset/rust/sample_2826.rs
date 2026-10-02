fn initialize_grid(size: usize) -> Vec<Vec<usize>> {
    let mut grid = vec![vec![0; size]; size];
    grid[size / 2][size / 2] = 1;
    grid
}

fn update_grid(grid: &Vec<Vec<usize>>) -> Vec<Vec<usize>> {
    let mut new_grid = grid.clone();
    for i in 0..grid.len() {
        for j in 0..grid[i].len() {
            let neighbors = (i as isize - 1..=i as isize + 1)
                .flat_map(|x| (j as isize - 1..=j as isize + 1).map(move |y| (x, y)))
                .filter(|&(x, y)| x >= 0 && x < grid.len() as isize && y >= 0 && y < grid[i].len() as isize && (x, y) != (i as isize, j as isize))
                .map(|(x, y)| grid[x as usize][y as usize])
                .sum::<usize>();
            new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
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