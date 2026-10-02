use rand::Rng;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![0; size]; size];
    let mut rng = rand::thread_rng();
    for i in 0..size {
        for j in 0..size {
            grid[i][j] = rng.gen_range(0..2);
        }
    }
    grid
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let neighbors = (0..3)
                .flat_map(|dx| (0..3).map(move |dy| (dx, dy)))
                .filter(|&(dx, dy)| (dx, dy) != (1, 1))
                .map(|(dx, dy)| grid[(i + dx) % size][(j + dy) % size])
                .sum::<i32>();
            new_grid[i][j] = if neighbors == 3 { 1 } else if neighbors == 2 { grid[i][j] } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut grid = initialize_grid(10);
    loop {
        grid = update_grid(&grid);
        for row in &grid {
            println!("{}", row.iter().map(|&cell| if cell == 1 { 'O' } else { ' ' }).collect::<String>());
        }
        println!();
    }
}