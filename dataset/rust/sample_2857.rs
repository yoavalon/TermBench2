fn update_state(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for r in 0..rows {
        for c in 0..cols {
            let neighbors: Vec<i32> = vec![
                (r as i32 - 1, c as i32),
                (r as i32 + 1, c as i32),
                (r as i32, c as i32 - 1),
                (r as i32, c as i32 + 1)
            ].into_iter()
            .filter(|&(x, y)| x >= 0 && x < rows as i32 && y >= 0 && y < cols as i32)
            .map(|(x, y)| grid[x as usize][y as usize])
            .collect();
            new_grid[r][c] = if neighbors.iter().sum::<i32>() == 3 { 1 } else { grid[r][c] };
        }
    }
    new_grid
}

fn run_simulation() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        grid = update_state(&grid);
        for row in &grid {
            for cell in row {
                print!("{}", if *cell == 1 { 'O' } else { ' ' });
            }
            println!();
        }
        println!();
    }
}

fn main() {
    run_simulation();
}