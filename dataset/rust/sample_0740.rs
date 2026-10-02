fn update_state(grid: Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for dy in [-1, 0, 1] {
                for dx in [-1, 0, 1] {
                    if dy == 0 && dx == 0 {
                        continue;
                    }
                    let nx = x as i32 + dx;
                    let ny = y as i32 + dy;
                    if nx >= 0 && nx < width as i32 && ny >= 0 && ny < height as i32 {
                        neighbors += grid[ny as usize][nx as usize];
                    }
                }
            }
            if grid[y][x] == 1 {
                new_grid[y][x] = if 2 <= neighbors && neighbors <= 3 { 1 } else { 0 };
            } else {
                new_grid[y][x] = if neighbors == 3 { 1 } else { 0 };
            }
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, width: usize, height: usize, steps: usize) -> Vec<Vec<i32>> {
    if steps == 0 {
        grid
    } else {
        simulate(update_state(grid, width, height), width, height, steps - 1)
    }
}

fn main() {
    let width = 50;
    let height = 50;
    let steps = 100;
    let grid = (0..height)
        .map(|y| (0..width).map(|x| if (x + y) % 2 == 0 { 1 } else { 0 }).collect())
        .collect();
    let final_grid = simulate(grid, width, height, steps);
    for row in final_grid {
        println!("{}", row.iter().map(|&cell| if cell == 1 { 'O' } else { ' ' }).collect::<String>());
    }
}