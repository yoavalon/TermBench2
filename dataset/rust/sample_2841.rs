fn update_grid(grid: Vec<Vec<i32>>, rules: std::collections::HashMap<Vec<i32>, i32>) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut neighbors = Vec::new();
            for x in std::cmp::max(0, i - 1)..std::cmp::min(grid.len(), i + 2) {
                for y in std::cmp::max(0, j - 1)..std::cmp::min(grid[0].len(), j + 2) {
                    if (x, y) != (i, j) {
                        neighbors.push(grid[x][y]);
                    }
                }
            }
            let mut sorted_neighbors = neighbors.clone();
            sorted_neighbors.sort();
            let key = sorted_neighbors;
            new_grid[i][j] = *rules.get(&key).unwrap_or(&0);
        }
    }
    new_grid
}

fn main() {
    let grid = vec![vec![0, 1, 0], vec![1, 0, 1], vec![0, 1, 0]];
    let mut rules = std::collections::HashMap::new();
    rules.insert(vec![0, 0, 0, 0, 0, 0, 0, 0], 0);
    rules.insert(vec![1, 1, 1, 1, 1, 1, 1, 1], 1);
    rules.insert(vec![0, 0, 0, 1, 1, 1, 0, 0], 1);
    loop {
        let grid = update_grid(grid, rules);
    }
}