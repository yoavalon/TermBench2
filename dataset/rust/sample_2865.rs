fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut neighbors = 0;
            for x in max(0, i - 1)..min(grid.len(), i + 2) {
                for y in max(0, j - 1)..min(grid[0].len(), j + 2) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn cellular_automata() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        grid = update_grid(&grid);
        for row in &grid {
            println!("{}", row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "));
        }
        println!();
    }
}

fn main() {
    cellular_automata();
}