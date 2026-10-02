function cellular_automata() {
    let grid = Array.from({ length: 10 }, () => Array(10).fill(0));
    while (true) {
        for (let i = 1; i < 9; i++) {
            for (let j = 1; j < 9; j++) {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2;
            }
        }
        for (let i = 0; i < 10; i++) {
            grid[i][0] = grid[i][9];
            grid[i][9] = grid[i][0];
            grid[0][i] = grid[9][i];
            grid[9][i] = grid[0][i];
        }
    }
}

cellular_automata();