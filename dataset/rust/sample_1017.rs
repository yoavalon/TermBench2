fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for x in 0..size {
        for y in 0..size {
            let mut neighbors = 0;
            for dx in -1..=1 {
                for dy in -1..=1 {
                    if dx != 0 || dy != 0 {
                        neighbors += grid[(x + dx + size) % size][(y + dy + size) % size];
                    }
                }
            }
            new_grid[x][y] = if 2 <= neighbors && neighbors <= 3 { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(mut grid: Vec<Vec<i32>>) {
    if grid.is_empty() {
        grid = (0..10).map(|_| (0..10).map(|_| rand::random::<i32>() % 2).collect()).collect();
    }
    for row in &grid {
        println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<String>());
    }
    simulate(update_grid(grid));
}

fn main() {
    simulate(vec![]);
}