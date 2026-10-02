use rand::Rng;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    let mut grid = Vec::with_capacity(size);
    for _ in 0..size {
        let row: Vec<i32> = (0..size).map(|_| rand::thread_rng().gen_range(0..=1)).collect();
        grid.push(row);
    }
    grid
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for x in [-1, 0, 1].iter() {
                for y in [-1, 0, 1].iter() {
                    if x == &0 && y == &0 {
                        continue;
                    }
                    let ni = (i as isize + x + size as isize) % size as isize;
                    let nj = (j as isize + y + size as isize) % size as isize;
                    neighbors += grid[ni as usize][nj as usize];
                }
            }
            if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) {
                new_grid[i][j] = 1;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let grid_size = 50;
    let mut grid = initialize_grid(grid_size);
    loop {
        grid = update_grid(&grid);
    }
}