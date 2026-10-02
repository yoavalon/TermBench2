fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = (0..3)
                .flat_map(|x| (0..3).map(move |y| (x, y)))
                .filter(|&(x, y)| x != 0 || y != 0)
                .map(|(x, y)| grid.get((i as isize + x - 1) as usize).and_then(|row| row.get((j as isize + y - 1) as usize)).unwrap_or(&0))
                .sum::<i32>();
            new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, steps: usize) -> Vec<Vec<i32>> {
    let mut current_grid = grid;
    for _ in 0..steps {
        current_grid = update_grid(current_grid);
    }
    current_grid
}

fn main() {
    let initial_grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    let steps = 5;
    let final_grid = simulate(initial_grid, steps);
    for row in final_grid {
        println!("{}", row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "));
    }
}