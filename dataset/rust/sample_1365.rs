fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut live_neighbors = 0;
            for x in -1..=1 {
                for y in -1..=1 {
                    if x != 0 || y != 0 {
                        let ni = i as isize + x;
                        let nj = j as isize + y;
                        if ni >= 0 && ni < rows as isize && nj >= 0 && nj < cols as isize {
                            live_neighbors += grid[ni as usize][nj as usize];
                        }
                    }
                }
            }
            new_grid[i][j] = if live_neighbors == 3 || (grid[i][j] == 1 && live_neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    for _ in 0..10 {
        grid = update_grid(grid);
        for row in &grid {
            for &cell in row {
                print!("{}", if cell == 1 { 'X' } else { ' ' });
            }
            println!();
        }
        println!();
    }
}