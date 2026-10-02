fn update_grid(grid: &Vec<Vec<i32>>, rule: &dyn Fn(&Vec<i32>, i32) -> i32) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut neighbors = Vec::new();
            for di in [-1, 0, 1] {
                for dj in [-1, 0, 1] {
                    if di != 0 || dj != 0 {
                        neighbors.push(grid[(i + di as usize) % grid.len()][(j + dj as usize) % grid[0].len()]);
                    }
                }
            }
            new_grid[i][j] = rule(&neighbors, grid[i][j]);
        }
    }
    new_grid
}

fn evolve(grid: &mut Vec<Vec<i32>>, rule: &dyn Fn(&Vec<i32>, i32) -> i32, steps: usize) {
    for _ in 0..steps {
        *grid = update_grid(grid, rule);
    }
}

fn main() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];

    let rule = |neighbors: &Vec<i32>, cell: i32| -> i32 {
        if neighbors.iter().sum::<i32>() == 3 { 1 } else { 0 }
    };

    loop {
        evolve(&mut grid, &rule, 1);
    }
}