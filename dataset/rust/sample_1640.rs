use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = (0..3).flat_map(|di| {
                (0..3).map(move |dj| {
                    let ni = (i as i32 + di - 1).max(0).min(rows as i32 - 1) as usize;
                    let nj = (j as i32 + dj - 1).max(0).min(cols as i32 - 1) as usize;
                    grid[ni][nj]
                })
            }).sum::<i32>() - grid[i][j];
            if grid[i][j] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    *grid = new_grid;
}

fn main() {
    let size = 50;
    let mut grid: Vec<Vec<i32>> = (0..size).map(|_| {
        (0..size).map(|_| rand::thread_rng().gen_range(0..2)).collect()
    }).collect();
    loop {
        update_grid(&mut grid);
    }
}