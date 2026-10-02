fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = (0.max(i as i32 - 1)..=(i + 1).min(rows as i32 - 1))
                .flat_map(|x| (0.max(j as i32 - 1)..=(j + 1).min(cols as i32 - 1)).map(move |y| (x, y)))
                .filter(|&(x, y)| (x, y) != (i as i32, j as i32))
                .map(|(x, y)| grid[x as usize][y as usize])
                .sum::<i32>();
            new_grid[i][j] = if neighbors == 3 { 1 } else if grid[i][j] == 1 && neighbors == 2 { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>) {
    simulate(update_grid(&grid));
}

fn main() {
    let grid_size = 10;
    let initial_grid: Vec<Vec<i32>> = (0..grid_size)
        .map(|i| (0..grid_size).map(|j| if i % 2 == 0 || j % 2 == 0 { 0 } else { 1 }).collect())
        .collect();
    simulate(initial_grid);
}