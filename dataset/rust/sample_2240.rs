fn update_grid(grid: &Vec<Vec<f64>>, width: usize, height: usize) -> Vec<Vec<f64>> {
    let mut new_grid = vec![vec![0.0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0.0;
            for i in -1..=1 {
                for j in -1..=1 {
                    if i == 0 && j == 0 {
                        continue;
                    }
                    let nx = (x as isize + i + width as isize) % width as isize;
                    let ny = (y as isize + j + height as isize) % height as isize;
                    neighbors += grid[ny as usize][nx as usize];
                }
            }
            new_grid[y][x] = neighbors / 9.0;
        }
    }
    new_grid
}

fn simulate(width: usize, height: usize) {
    let mut grid = vec![vec![0.0; width]; height];
    loop {
        grid = update_grid(&grid, width, height);
    }
}

fn main() {
    simulate(100, 100);
}