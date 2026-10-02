fn cellular_automata(size: usize, steps: usize) -> Vec<Vec<usize>> {
    let mut grid = vec![vec![0; size]; size];
    for _ in 0..steps {
        let mut new_grid = vec![vec![0; size]; size];
        for i in 0..size {
            for j in 0..size {
                let mut neighbors = 0;
                for dx in -1..=1 {
                    for dy in -1..=1 {
                        neighbors += grid[(i + (dx as usize)) % size][(j + (dy as usize)) % size];
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
    grid
}

fn main() {
    cellular_automata(10, 5);
}