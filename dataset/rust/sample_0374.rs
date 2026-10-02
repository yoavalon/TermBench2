use rand::Rng;

fn simulate() {
    let mut grid = vec![vec![0; 10]; 10];
    let mut rng = rand::thread_rng();

    for i in 0..10 {
        for j in 0..10 {
            grid[i][j] = if rng.gen_bool(0.5) { 1 } else { 0 };
        }
    }

    loop {
        let mut new_grid = vec![vec![0; 10]; 10];
        for i in 0..10 {
            for j in 0..10 {
                let neighbors = [
                    (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)
                ].iter()
                .filter(|&&(dx, dy)| {
                    0 <= i + dx && i + dx < 10 && 0 <= j + dy && j + dy < 10
                })
                .map(|&(dx, dy)| grid[i + dx][j + dy])
                .sum::<u32>();

                new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
}

fn main() {
    simulate();
}