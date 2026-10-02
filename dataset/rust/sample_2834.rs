use rand::Rng;

fn update_state(grid: &mut [[u8; 100]; 100]) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = [[0; 100]; 100];
    for i in 0..rows {
        for j in 0..cols {
            let mut neighbors = 0;
            for di in -1..=1 {
                for dj in -1..=1 {
                    if di == 0 && dj == 0 {
                        continue;
                    }
                    let ni = (i as isize + di + rows as isize) as usize % rows;
                    let nj = (j as isize + dj + cols as isize) as usize % cols;
                    neighbors += grid[ni][nj];
                }
            }
            if grid[i][j] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    new_grid[i][j] = 0;
                }
            } else if neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    *grid = new_grid;
}

fn main() {
    let mut grid = [[0; 100]; 100];
    let mut rng = rand::thread_rng();
    for i in 0..100 {
        for j in 0..100 {
            grid[i][j] = rng.gen_range(0..2);
        }
    }
    loop {
        update_state(&mut grid);
    }
}