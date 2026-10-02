fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; grid[0].len()]; grid.len()];
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut count = 0;
            for x in (i - 1)..=(i + 1) {
                for y in (j - 1)..=(j + 1) {
                    if x >= 0 && x < grid.len() && y >= 0 && y < grid[0].len() && (x, y) != (i, j) {
                        count += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if grid[i][j] == 1 && (count == 2 || count == 3) { 1 } else if count == 3 { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, steps: i32) -> Vec<Vec<i32>> {
    let mut current_grid = grid;
    for _ in 0..steps {
        current_grid = update_grid(&current_grid);
    }
    current_grid
}

fn main() {
    let initial_grid = vec![
        vec![0, 0, 0, 0, 0],
        vec![0, 1, 1, 1, 0],
        vec![0, 0, 0, 0, 0],
        vec![0, 0, 1, 0, 0],
        vec![0, 0, 0, 0, 0],
    ];
    let final_grid = simulate(initial_grid, 10);
    for row in final_grid {
        println!("{:?}", row);
    }
}