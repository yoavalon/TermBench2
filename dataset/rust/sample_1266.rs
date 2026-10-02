use rand::Rng;

fn cellular_automata(n: usize, m: usize, steps: usize) -> Vec<Vec<u8>> {
    let mut grid = vec![vec![0; m]; n];
    let mut rng = rand::thread_rng();

    for i in 0..n {
        for j in 0..m {
            grid[i][j] = if rng.gen_bool(0.5) { 1 } else { 0 };
        }
    }

    for _ in 0..steps {
        let mut new_grid = grid.clone();
        for i in 0..n {
            for j in 0..m {
                let neighbors = (0..3).map(|di| {
                    (0..3).map(|dj| {
                        grid[(i + di - 1).max(0).min(n - 1)][(j + dj - 1).max(0).min(m - 1)]
                    }).sum::<u8>()
                }).sum::<u8>() - grid[i][j];
                new_grid[i][j] = if neighbors == 3 || (neighbors == 2 && grid[i][j] == 1) { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }

    grid
}

fn main() {
    let result = cellular_automata(10, 10, 5);
    for row in result {
        println!("{:?}", row);
    }
}