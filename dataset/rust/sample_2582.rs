use rand::Rng;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![0; size]; size];
    let mut rng = rand::thread_rng();
    for i in 0..size {
        for j in 0..size {
            grid[i][j] = rng.gen_range(0..2);
        }
    }
    grid
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for di in -1..=1 {
                for dj in -1..=1 {
                    if (di, dj) != (0, 0) {
                        neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
        }
    }
    new_grid
}

fn simulate(steps: usize, size: usize) -> Vec<Vec<i32>> {
    let mut grid = initialize_grid(size);
    for _ in 0..steps {
        grid = update_grid(&grid);
    }
    grid
}

fn main() {
    let steps = 10;
    let size = 5;
    let result = simulate(steps, size);
    for row in result {
        println!("{}", row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "));
    }
}