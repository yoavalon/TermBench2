fn update_grid(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = Vec::new();
            for di in -1..=1 {
                for dj in -1..=1 {
                    if i as i32 + di >= 0 && i as i32 + di < rows as i32 && j as i32 + dj >= 0 && j as i32 + dj < cols as i32 {
                        neighbors.push(grid[(i as i32 + di) as usize][(j as i32 + dj) as usize]);
                    }
                }
            }
            new_grid[i][j] = neighbors.iter().sum::<i32>() / neighbors.len() as i32;
        }
    }
    new_grid
}

fn display(grid: &Vec<Vec<i32>>) {
    for row in grid {
        for cell in row {
            print!("{} ", cell);
        }
        println!();
    }
    println!();
}

fn simulate(grid: Vec<Vec<i32>>) {
    display(&grid);
    simulate(update_grid(grid));
}

fn main() {
    let grid = vec![vec![0, 1, 0], vec![1, 0, 1], vec![0, 1, 0]];
    simulate(grid);
}