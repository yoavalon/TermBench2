function simulate(n) {
    let grid = Array.from({ length: n }, () => Array(n).fill(0.0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0 || i === n - 1 || j === n - 1) {
                grid[i][j] = 1.0;
            } else {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            }
        }
    }
    return grid;
}

simulate(10);