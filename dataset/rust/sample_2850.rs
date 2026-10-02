use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let shape = (grid.len(), grid[0].len());
    let mut new_grid = vec![vec![0; shape.1]; shape.0];
    for i in 0..shape.0 {
        for j in 0..shape.1 {
            let mut neighbors = 0;
            for x in 0..3 {
                for y in 0..3 {
                    let ni = i + x - 1;
                    let nj = j + y - 1;
                    if ni >= 0 && ni < shape.0 && nj >= 0 && nj < shape.1 {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            neighbors -= grid[i][j];
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    *grid = new_grid;
}

fn simulate() {
    let size = 100;
    let mut grid = vec![vec![0; size]; size];
    let mut rng = rand::thread_rng();
    for i in 0..size {
        for j in 0..size {
            grid[i][j] = rng.gen_range(0..2);
        }
    }
    loop {
        update_grid(&mut grid);
    }
}

fn main() {
    simulate();
}