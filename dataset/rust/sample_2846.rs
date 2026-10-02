use rand::Rng;

fn generate_grid(size: usize) -> Vec<Vec<i32>> {
    let mut grid = Vec::with_capacity(size);
    for _ in 0..size {
        let mut row = Vec::with_capacity(size);
        for _ in 0..size {
            row.push(rand::thread_rng().gen_range(0..2));
        }
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
            for dx in -1..=1 {
                for dy in -1..=1 {
                    if dx == 0 && dy == 0 {
                        continue;
                    }
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            if (grid[i][j] == 1 && neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut grid = generate_grid(size);
    loop {
        grid = update_grid(&grid);
    }
}