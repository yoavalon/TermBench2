fn update(grid: &Vec<Vec<i32>>, size: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for dx in -1..=1 {
                for dy in -1..=1 {
                    if dx == 0 && dy == 0 { continue; }
                    neighbors += grid[(i + (dx as usize + size) % size)][(j + (dy as usize + size) % size)];
                }
            }
            new_grid[i][j] = if neighbors == 3 { 1 } else if neighbors == 2 { grid[i][j] } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, size: usize) {
    let output: Vec<String> = grid.iter().map(|row| row.iter().map(|&cell| if cell == 1 { '#' } else { ' ' }).collect()).collect();
    println!("{}", output.join("\n"));
    simulate(update(&grid, size), size);
}

fn main() {
    let size = 10;
    let mut grid = vec![vec![0; size]; size];
    grid[size / 2][size / 2] = 1;
    simulate(grid, size);
}