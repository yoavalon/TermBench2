fn cellular_automata() {
    let mut grid = vec![vec![0, 1, 0], vec![0, 1, 0], vec![0, 1, 0]];
    loop {
        let mut new_grid = vec![vec![0, 0, 0], vec![0, 0, 0], vec![0, 0, 0]];
        for i in 0..3 {
            for j in 0..3 {
                let mut live_neighbors = 0;
                for x in i - 1..=i + 1 {
                    for y in j - 1..=j + 1 {
                        if (0 <= x && x < 3) && (0 <= y && y < 3) && (x != i || y != j) && grid[x][y] == 1 {
                            live_neighbors += 1;
                        }
                    }
                }
                new_grid[i][j] = if live_neighbors == 2 { 1 } else { 0 };
            }
        }
        grid = new_grid;
    }
}

fn main() {
    cellular_automata();
}