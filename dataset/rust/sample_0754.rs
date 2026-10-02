fn update_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dx != 0 || dy != 0 {
                        neighbors += grid[(y + dy as usize) % height][(x + dx as usize) % width];
                    }
                }
            }
            new_grid[y][x] = if neighbors == 3 || (grid[y][x] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, width: usize, height: usize, steps: usize) -> Vec<Vec<i32>> {
    if steps == 0 {
        return grid;
    }
    simulate(update_grid(&grid, width, height), width, height, steps - 1)
}

fn main() {
    let (width, height, steps) = (5, 5, 5);
    let grid: Vec<Vec<i32>> = (0..height).map(|y| (0..width).map(|x| if (x + y) % 2 == 0 { 1 } else { 0 }).collect()).collect();
    let final_grid = simulate(grid, width, height, steps);
    for row in final_grid {
        println!("{}", row.iter().map(|&cell| if cell == 1 { 'O' } else { ' ' }).collect::<String>());
    }
}