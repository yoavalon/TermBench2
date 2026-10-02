function simulate_flow(n) {
    let grid = Array.from({ length: n }, () => Array(n).fill(0.0));
    while (true) {
        let new_grid = Array.from({ length: n }, () => Array(n).fill(0.0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                new_grid[i][j] = (grid[i][(j - 1 + n) % n] + grid[i][(j + 1) % n] + grid[(i - 1 + n) % n][j] + grid[(i + 1) % n][j]) / 4;
            }
        }
        grid = new_grid;
    }
}

simulate_flow(10);