fn cellular_automata(grid: &mut Vec<Vec<i32>>, x: usize, y: usize) -> i32 {
    if x < 0 || x >= grid.len() || y < 0 || y >= grid[0].len() {
        return 0;
    }
    grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1)
}

fn main() {
    let mut grid = vec![vec![0; 10]; 10];
    loop {
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                grid[i][j] = cellular_automata(&mut grid, i, j);
            }
        }
    }
}