fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for di in [-1, 0, 1] {
                for dj in [-1, 0, 1] {
                    if di == 0 && dj == 0 {
                        continue;
                    }
                    let ni = i as isize + di;
                    let nj = j as isize + dj;
                    if ni >= 0 && ni < rows as isize && nj >= 0 && nj < cols as isize {
                        neighbors += grid[ni as usize][nj as usize];
                    }
                }
            }
            if grid[i][j] == 1 {
                new_grid[i][j] = if neighbors >= 2 && neighbors <= 3 { 1 } else { 0 };
            } else {
                new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
            }
        }
    }
    new_grid
}

fn main() {
    let mut initial_grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    for _ in 0..10 {
        initial_grid = update_grid(initial_grid);
        for row in initial_grid.iter() {
            let line: String = row.iter().map(|&cell| if cell == 1 { '#' } else { ' ' }).collect();
            println!("{}", line);
        }
        println!();
    }
}