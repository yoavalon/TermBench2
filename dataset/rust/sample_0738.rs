fn update_grid(grid: &Vec<Vec<i32>>, size: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for x in (0.max(i as isize - 1)) as usize..(size.min(i + 2)) {
                for y in (0.max(j as isize - 1)) as usize..(size.min(j + 2)) {
                    if (x, y) != (i, j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 || (neighbors == 2 && grid[i][j] == 1) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, size: usize, steps: usize) -> Vec<Vec<i32>> {
    if steps == 0 {
        return grid;
    }
    simulate(update_grid(&grid, size), size, steps - 1)
}

fn main() {
    let size = 10;
    let mut initial_grid = vec![vec![0; size]; size];
    initial_grid[5][5] = 1;
    initial_grid[5][6] = 1;
    initial_grid[6][5] = 1;
    initial_grid[6][6] = 1;
    let final_grid = simulate(initial_grid, size, 10);
    for row in final_grid {
        println!("{}", row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "));
    }
}