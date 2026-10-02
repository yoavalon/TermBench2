use rand::Rng;

fn cellular_automata() {
    let mut grid: Vec<i32> = (0..100).map(|_| rand::thread_rng().gen_range(0..2)).collect();
    loop {
        let mut new_grid = Vec::new();
        for i in 0..grid.len() {
            let left = grid[(i + grid.len() - 1) % grid.len()];
            let center = grid[i];
            let right = grid[(i + 1) % grid.len()];
            new_grid.push(if left + center + right == 2 { 1 } else { 0 });
        }
        grid = new_grid;
    }
}

fn main() {
    cellular_automata();
}