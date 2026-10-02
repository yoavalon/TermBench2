fn update_state(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
                .iter()
                .filter(|&&(x, y)| x >= 0 && x < grid.len() as i32 && y >= 0 && y < grid[0].len() as i32)
                .map(|&(x, y)| grid[x as usize][y as usize])
                .sum::<i32>();
            new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: &mut Vec<Vec<i32>>) {
    loop {
        *grid = update_state(grid);
        for row in grid {
            println!("{}", row.iter().map(|&cell| cell.to_string()).collect::<Vec<_>>().join(" "));
        }
        println!();
    }
}

fn main() {
    let mut initial_grid = vec![
        vec![0, 0, 0, 0, 0],
        vec![0, 1, 1, 0, 0],
        vec![0, 1, 1, 0, 0],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0],
    ];
    simulate(&mut initial_grid);
}