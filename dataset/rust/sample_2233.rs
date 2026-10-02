fn update_state(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = vec![
                grid[(i + rows - 1) % rows][(j + cols - 1) % cols],
                grid[(i + rows - 1) % rows][j],
                grid[(i + rows - 1) % rows][(j + 1) % cols],
                grid[i][(j + cols - 1) % cols],
                grid[i][(j + 1) % cols],
                grid[(i + 1) % rows][(j + cols - 1) % cols],
                grid[(i + 1) % rows][j],
                grid[(i + 1) % rows][(j + 1) % cols],
            ];
            let live_neighbors = neighbors.iter().sum::<i32>();
            if grid[i][j] == 1 {
                if live_neighbors < 2 || live_neighbors > 3 {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if live_neighbors == 3 {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    new_grid
}

fn main() {
    let mut grid = vec![
        vec![0, 1, 0, 0, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 1, 1, 1, 0],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0],
    ];
    loop {
        grid = update_state(&grid);
        for row in &grid {
            println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<String>>().join(" "));
        }
        println!();
    }
}