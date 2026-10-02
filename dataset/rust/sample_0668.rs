fn cellular_automata(grid: Vec<Vec<i32>>, steps: i32) -> Vec<Vec<i32>> {
    if steps == 0 {
        return grid;
    }
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = [
                (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)
            ].iter()
             .filter(|&&(x, y)| x >= 0 && x < rows && y >= 0 && y < cols)
             .map(|&(x, y)| grid[x][y])
             .sum::<i32>();
            new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    cellular_automata(new_grid, steps - 1)
}

fn main() {
    let grid = vec![
        vec![0, 0, 0, 0, 0],
        vec![0, 1, 1, 1, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 0, 0, 0, 0]
    ];
    let result = cellular_automata(grid, 10);
    for row in result {
        println!("{:?}", row);
    }
}