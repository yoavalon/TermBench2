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
            let neighbors = (0..3).flat_map(|x| {
                (0..3).map(move |y| {
                    let ix = (i + x - 1) % size;
                    let jy = (j + y - 1) % size;
                    grid[ix][jy]
                })
            }).sum::<usize>();
            if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                new_grid[i][j] = 1;
            }
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