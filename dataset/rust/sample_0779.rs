fn update_grid(grid: Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dx == 0 && dy == 0 {
                        continue;
                    }
                    neighbors += grid[(y + dy as usize) % height][(x + dx as usize) % width];
                }
            }
            new_grid[y][x] = if neighbors == 3 { 1 } else { grid[y][x] };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, width: usize, height: usize, steps: usize) -> Vec<Vec<i32>> {
    if steps == 0 {
        return grid;
    }
    simulate(update_grid(grid, width, height), width, height, steps - 1)
}

fn main() {
    let (width, height, steps) = (10, 10, 5);
    let initial_grid: Vec<Vec<i32>> = (0..height).map(|y| (0..width).map(|x| if x == y { 1 } else { 0 }).collect()).collect();
    let final_grid = simulate(initial_grid, width, height, steps);
    for row in final_grid {
        println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
    }
}