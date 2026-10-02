fn init_grid(size: usize) -> Vec<Vec<i32>> {
    (0..size).map(|y| {
        (0..size).map(|x| {
            if x != 0 && x != size - 1 && y != 0 && y != size - 1 {
                0
            } else {
                1
            }
        }).collect()
    }).collect()
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = grid.clone();
    for y in 1..grid.len() - 1 {
        for x in 1..grid[0].len() - 1 {
            let neighbors = vec![
                grid[y - 1][x],
                grid[y + 1][x],
                grid[y][x - 1],
                grid[y][x + 1],
            ];
            new_grid[y][x] = if neighbors.iter().sum::<i32>() >= 2 { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>) {
    let mut current_grid = grid;
    loop {
        current_grid = update_grid(&current_grid);
    }
}

fn main() {
    let size = 10;
    let grid = init_grid(size);
    simulate(grid);
}