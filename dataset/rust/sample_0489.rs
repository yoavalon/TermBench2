fn update_grid(grid: &Vec<Vec<i32>>, width: usize, height: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let neighbors = [
                (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)
            ].iter().map(|&(dx, dy)| {
                grid[(y + dy as usize) % height][(x + dx as usize) % width]
            }).sum::<i32>();
            if grid[y][x] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[y][x] = 0;
            } else if grid[y][x] == 0 && neighbors == 3 {
                new_grid[y][x] = 1;
            } else {
                new_grid[y][x] = grid[y][x];
            }
        }
    }
    new_grid
}

fn main() {
    let width = 10;
    let height = 10;
    let mut grid = (0..height).map(|y| (0..width).map(|x| (x + y) % 2 as i32).collect()).collect();
    loop {
        grid = update_grid(&grid, width, height);
    }
}