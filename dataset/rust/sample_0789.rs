fn update_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for (dy, dx) in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)].iter() {
                neighbors += grid[(y + dy.abs() as usize) % height][(x + dx.abs() as usize) % width];
            }
            new_grid[y][x] = if neighbors == 3 || (grid[y][x] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: &Vec<Vec<i32>>, width: usize, height: usize, steps: usize) -> Vec<Vec<i32>> {
    if steps == 0 {
        return grid.clone();
    }
    simulate(&update_grid(grid, width, height), width, height, steps - 1)
}

fn main() {
    let width = 10;
    let height = 10;
    let initial_grid: Vec<Vec<i32>> = (0..height).map(|y| (0..width).map(|x| if x % 2 == 0 { 1 } else { 0 }).collect()).collect();
    let steps = 5;
    let final_grid = simulate(&initial_grid, width, height, steps);
    for row in final_grid {
        println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
    }
}