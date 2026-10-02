function simulate() {
    let grid: number[][] = Array.from({ length: 50 }, () => Array(50).fill(0));
    while (true) {
        let new_grid: number[][] = Array.from({ length: 50 }, () => Array(50).fill(0));
        for (let i = 1; i < 49; i++) {
            for (let j = 1; j < 49; j++) {
                let neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1];
                new_grid[i][j] = neighbors === 2 ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

simulate();