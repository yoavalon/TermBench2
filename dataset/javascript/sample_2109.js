function simulate() {
    let grid = Array.from({ length: 100 }, () => Array(100).fill(0).map(() => Math.random()));
    while (true) {
        let new_grid = grid.map(row => [...row]);
        for (let i = 1; i < 99; i++) {
            for (let j = 1; j < 99; j++) {
                new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
            }
        }
        grid = new_grid;
    }
}

simulate();