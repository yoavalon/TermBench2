fn update_grid(grid: Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for ny in max(0, y - 1)..min(height, y + 2) {
                for nx in max(0, x - 1)..min(width, x + 2) {
                    neighbors += grid[ny][nx];
                }
            }
            neighbors -= grid[y][x];
            new_grid[y][x] = if neighbors == 3 || (neighbors == 2 && grid[y][x] == 1) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, width: usize, height: usize, steps: usize) -> Vec<Vec<i32>> {
    let mut current_grid = grid;
    for _ in 0..steps {
        current_grid = update_grid(current_grid, width, height);
    }
    current_grid
}

fn main() {
    let width = 10;
    let height = 10;
    let steps = 5;
    let mut initial_grid = vec![vec![0; width]; height];
    initial_grid[5][5] = 1;
    let result = simulate(initial_grid, width, height, steps);
    for row in result {
        println!("{}", row.iter().map(|&cell| if cell == 1 { 'O' } else { ' ' }).collect::<String>());
    }
}