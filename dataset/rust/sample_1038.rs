fn update_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = 0;
            for i in -1..=1 {
                for j in -1..=1 {
                    let nx = (x as i32 + i + width as i32) % width as i32;
                    let ny = (y as i32 + j + height as i32) % height as i32;
                    neighbors += grid[ny as usize][nx as usize];
                }
            }
            new_grid[y][x] = if 2 < neighbors && neighbors < 4 { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, width: usize, height: usize) {
    print_grid(&grid, width, height);
    simulate(update_grid(&grid, width, height), width, height);
}

fn print_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) {
    for y in 0..height {
        let row: String = (0..width).map(|x| if grid[y][x] == 1 { '#' } else { ' ' }).collect();
        println!("{}", row);
    }
}

fn main() {
    let width = 50;
    let height = 50;
    let mut grid = vec![vec![0; width]; height];
    grid[25][25] = 1;
    simulate(grid, width, height);
}