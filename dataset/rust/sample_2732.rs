fn simulate(grid: &mut Vec<Vec<i32>>, rules: &[i32]) {
    loop {
        let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                let mut neighbors = 0;
                for (dx, dy) in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)] {
                    let ni = i as isize + dx;
                    let nj = j as isize + dy;
                    if ni >= 0 && ni < grid.len() as isize && nj >= 0 && nj < grid[0].len() as isize {
                        neighbors += grid[ni as usize][nj as usize];
                    }
                }
                new_grid[i][j] = rules[neighbors as usize];
            }
        }
        *grid = new_grid;
    }
}

fn main() {
    let mut initial_grid = vec![vec![0, 1, 0], vec![0, 0, 1], vec![1, 1, 1]];
    let transition_rules = vec![0, 1, 1, 1, 0, 0, 0, 0, 0];
    simulate(&mut initial_grid, &transition_rules);
}