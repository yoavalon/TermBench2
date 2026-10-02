use std::io::{stdout, Write};
use std::process::Command;

fn update_grid(grid: Vec<Vec<i32>>, rules: Vec<i32>) -> Vec<Vec<i32>> {
    let mut new_grid = grid.clone();
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let neighbors = (0..3)
                .flat_map(|x| (0..3).map(move |y| (x, y)))
                .filter(|&(dx, dy)| dx != 1 || dy != 1)
                .map(|(dx, dy)| {
                    let x = (i as i32 + dx - 1).max(0) as usize;
                    let y = (j as i32 + dy - 1).max(0) as usize;
                    grid[x][y]
                })
                .sum::<i32>() - grid[i][j];
            new_grid[i][j] = rules[neighbors as usize];
        }
    }
    new_grid
}

fn simulate(grid: Vec<Vec<i32>>, rules: Vec<i32>) {
    let clear_command = if cfg!(target_os = "windows") { "cls" } else { "clear" };
    Command::new(clear_command).status().unwrap();
    for row in grid.iter() {
        let row_str: String = row.iter().map(|&cell| if cell == 1 { '#' } else { '.' }).collect();
        print!("{}", row_str);
        stdout().flush().unwrap();
    }
    simulate(update_grid(grid, rules), rules);
}

fn main() {
    let width = 20;
    let height = 20;
    let initial_grid: Vec<Vec<i32>> = (0..height)
        .map(|i| (0..width).map(|j| if (i + j) % 2 == 0 { 1 } else { 0 }).collect())
        .collect();
    let rules = vec![0, 0, 1, 1, 0, 0, 0, 0, 0];
    simulate(initial_grid, rules);
}