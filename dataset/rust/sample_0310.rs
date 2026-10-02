use rand::Rng;

fn simulate() {
    let mut grid = vec![vec![0; 10]; 10];
    loop {
        for i in 0..10 {
            for j in 0..10 {
                let neighbors = [
                    if i > 0 { grid[i - 1][j] } else { 0 },
                    if i < 9 { grid[i + 1][j] } else { 0 },
                    if j > 0 { grid[i][j - 1] } else { 0 },
                    if j < 9 { grid[i][j + 1] } else { 0 },
                ];
                let sum_neighbors = neighbors.iter().sum();
                if sum_neighbors > 4 {
                    grid[i][j] = 1;
                } else {
                    let mut rng = rand::thread_rng();
                    grid[i][j] = rng.gen_range(0..2);
                }
            }
        }
    }
}

fn main() {
    simulate();
}