fn update_state(grid: Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dy == 0 && dx == 0 {
                        continue;
                    }
                    let nx = x as isize + dx;
                    let ny = y as isize + dy;
                    if nx >= 0 && nx < width as isize && ny >= 0 && ny < height as isize {
                        neighbors += grid[ny as usize][nx as usize];
                    }
                }
            }
            if grid[y][x] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    new_grid[y][x] = 0;
                } else {
                    new_grid[y][x] = 1;
                }
            } else if neighbors == 3 {
                new_grid[y][x] = 1;
            }
        }
    }
    new_grid
}

fn run_simulation(grid: Vec<Vec<i32>>, width: usize, height: usize, steps: usize) -> Vec<Vec<i32>> {
    if steps == 0 {
        grid
    } else {
        let grid = update_state(grid, width, height);
        run_simulation(grid, width, height, steps - 1)
    }
}

fn main() {
    let width = 10;
    let height = 10;
    let initial_grid = vec![
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    let steps = 10;
    let final_grid = run_simulation(initial_grid, width, height, steps);
    for row in final_grid {
        for &cell in &row {
            print!("{} ", cell);
        }
        println!();
    }
}