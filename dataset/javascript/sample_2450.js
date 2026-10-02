function simulate_cells(rows, cols, steps) {
    let grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let _ = 0; _ < steps; _++) {
        let new_grid = Array.from({ length: rows }, () => Array(cols).fill(0));
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                let neighbors = 0;
                for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                    for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                        if (x !== i || y !== j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (neighbors === 3 || (grid[i][j] && neighbors === 2)) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
    return grid;
}
simulate_cells(10, 10, 5);