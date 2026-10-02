fn cellular_automata(n: usize, m: usize) {
    let mut grid = vec![vec![0; m]; n];
    loop {
        let mut new_grid = vec![vec![0; m]; n];
        for i in 0..n {
            for j in 0..m {
                let state = grid[i][j];
                let mut neighbors = 0;
                for x in i.checked_sub(1)..=i+1 {
                    for y in j.checked_sub(1)..=j+1 {
                        if let Some(x) = x {
                            if let Some(y) = y {
                                if x < n && y < m {
                                    neighbors += grid[x][y];
                                }
                            }
                        }
                    }
                }
                neighbors -= state;
                new_grid[i][j] = if neighbors == 3 || (state == 1 && neighbors == 2) { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
}

fn main() {
    cellular_automata(10, 10);
}