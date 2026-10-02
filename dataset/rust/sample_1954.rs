fn update_grid(grid: &mut Vec<Vec<f64>>, width: usize, height: usize) -> Vec<Vec<f64>> {
    let mut new_grid = vec![vec![0.0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0.0;
            for dy in -1..2 {
                for dx in -1..2 {
                    if dx == 0 && dy == 0 {
                        continue;
                    }
                    let nx = (x as i32 + dx) as usize;
                    let ny = (y as i32 + dy) as usize;
                    if nx < width && ny < height {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x]);
        }
    }
    new_grid
}

fn main() {
    let width = 10;
    let height = 10;
    let mut grid: Vec<Vec<f64>> = (0..height)
        .map(|y| (0..width).map(|x| if x == y { 0.0 } else { 1.0 }).collect())
        .collect();
    for _ in 0..100 {
        grid = update_grid(&mut grid, width, height);
    }
    println!("{:?}", grid);
}