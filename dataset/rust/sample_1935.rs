use std::collections::VecDeque;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = grid.clone();

    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for x in 0..3 {
                for y in 0..3 {
                    if x == 1 && y == 1 {
                        continue;
                    }
                    let ni = i + x - 1;
                    let nj = j + y - 1;
                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if grid[i][j] == 1 {
                new_grid[i][j] = if 2 <= neighbors && neighbors <= 3 { 1 } else { 0 };
            } else {
                new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
            }
        }
    }
    *grid = new_grid;
}

fn main() {
    let grid_size = 10;
    let mut grid = vec![vec![0; grid_size]; grid_size];
    grid[grid_size / 2][grid_size / 2] = 1;
    let steps = 50;
    for _ in 0..steps {
        update_grid(&mut grid);
    }
    for row in &grid {
        println!("{:?}", row);
    }
}