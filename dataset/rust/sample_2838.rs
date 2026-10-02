fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = (0..rows)
                .flat_map(|x| (0..cols).map(move |y| (x, y)))
                .filter(|&(x, y)| x != i || y != j)
                .filter(|&(x, y)| grid[x][y] == 1)
                .count() as i32;
            if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        grid = update_grid(grid);
        for row in &grid {
            for &cell in row {
                if cell == 1 {
                    print!("█");
                } else {
                    print!(" ");
                }
            }
            println!();
        }
        println!();
    }
}