fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
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
            new_grid[i][j] = neighbors.iter().sum::<i32>() / 8;
        }
    }

    new_grid
}

fn simulate(mut grid: Vec<Vec<i32>>) {
    loop {
        grid = update_grid(&grid);
        for row in grid.iter() {
            println!("{}", row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "));
        }
        println!();
    }
}

fn main() {
    let initial_grid = vec![vec![1, 0, 1], vec![0, 1, 0], vec![1, 0, 1]];
    simulate(initial_grid);
}