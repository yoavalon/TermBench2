fn cellular_automata(mut grid: Vec<Vec<i32>>, steps: i32) -> Vec<Vec<i32>> {
    for _ in 0..steps {
        let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                let neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
                    .iter()
                    .filter(|&&(x, y)| x >= 0 && x < grid.len() as i32 && y >= 0 && y < grid[0].len() as i32)
                    .map(|&(x, y)| grid[x as usize][y as usize])
                    .sum::<i32>();
                new_grid[i][j] = if neighbors == 2 || (neighbors == 3 && grid[i][j] == 1) { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
    grid
}

fn main() {
    let initial_grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    let steps = 5;
    let result = cellular_automata(initial_grid, steps);
    for row in result {
        println!("{:?}", row);
    }
}