fn update_state(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = grid.clone();
    for y in 0..grid.len() {
        for x in 0..grid[y].len() {
            let mut neighbors = Vec::new();
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dy == 0 && dx == 0 {
                        continue;
                    }
                    let ny = y as isize + dy;
                    let nx = x as isize + dx;
                    if ny >= 0 && ny < grid.len() as isize && nx >= 0 && nx < grid[y.len() - 1].len() as isize {
                        neighbors.push(grid[ny as usize][nx as usize]);
                    }
                }
            }
            let count = neighbors.iter().sum::<i32>();
            if grid[y][x] == 1 && count < 2 {
                new_grid[y][x] = 0;
            } else if grid[y][x] == 1 && (count == 2 || count == 3) {
                new_grid[y][x] = 1;
            } else if grid[y][x] == 1 && count > 3 {
                new_grid[y][x] = 0;
            } else if grid[y][x] == 0 && count == 3 {
                new_grid[y][x] = 1;
            }
        }
    }
    new_grid
}

fn display_grid(grid: &Vec<Vec<i32>>) {
    for row in grid {
        let row_str: String = row.iter().map(|&cell| if cell == 1 { 'O' } else { ' ' }).collect();
        println!("{}", row_str);
    }
    println!();
}

fn simulate(grid: Vec<Vec<i32>>) {
    display_grid(&grid);
    simulate(update_state(&grid));
}

fn main() {
    let initial_grid = vec![
        vec![0, 0, 0, 0, 0],
        vec![0, 1, 1, 0, 0],
        vec![0, 1, 0, 1, 0],
        vec![0, 0, 1, 1, 0],
        vec![0, 0, 0, 0, 0]
    ];
    simulate(initial_grid);
}