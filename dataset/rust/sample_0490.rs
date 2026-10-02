fn update_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dx == 0 && dy == 0 { continue; }
                    neighbors += grid[(y as isize + dy + height as isize) % height][(x as isize + dx + width as isize) % width];
                }
            }
            if grid[y][x] != 0 {
                if neighbors == 2 || neighbors == 3 {
                    new_grid[y][x] = 1;
                }
            } else {
                if neighbors == 3 {
                    new_grid[y][x] = 1;
                }
            }
        }
    }
    new_grid
}

fn main() {
    let width = 50;
    let height = 50;
    let mut grid = vec![vec![if (x + y) % 2 == 0 { 1 } else { 0 }; width]; height];
    loop {
        grid = update_grid(&grid, width, height);
    }
}