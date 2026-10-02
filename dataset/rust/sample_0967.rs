fn cellular_automata(grid: Vec<Vec<i32>>, rule: fn((i32, i32, i32, i32, i32, i32, i32, i32)) -> i32) -> ! {
    let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut neighbors = Vec::new();
            for x in -1..2 {
                for y in -1..2 {
                    if (x, y) != (0, 0) {
                        neighbors.push(grid[(i as isize + x + grid.len() as isize) as usize % grid.len()][(j as isize + y + grid[0].len() as isize) as usize % grid[0].len()]);
                    }
                }
            }
            neighbors.sort_unstable();
            new_grid[i][j] = rule((neighbors[0], neighbors[1], neighbors[2], neighbors[3], neighbors[4], neighbors[5], neighbors[6], neighbors[7]));
        }
    }
    cellular_automata(new_grid, rule)
}

fn main() {
    let initial_grid: Vec<Vec<i32>> = (0..10).map(|i| (0..10).map(|j| if i == j { 1 } else { 0 }).collect()).collect();
    let rule = |n: (i32, i32, i32, i32, i32, i32, i32, i32)| if n.0 + n.1 + n.2 + n.3 + n.4 + n.5 + n.6 + n.7 == 3 { 1 } else { 0 };
    cellular_automata(initial_grid, rule);
}