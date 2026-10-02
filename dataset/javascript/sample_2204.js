function updateGrid(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let newGrid = Array.from({ length: rows }, () => Array(cols).fill(0.0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let total = 0.0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    let ni = i + di;
                    let nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        total += grid[ni][nj];
                    }
                }
            }
            newGrid[i][j] = total / 9.0;
        }
    }
    return newGrid;
}

function simulate() {
    let grid = Array.from({ length: 10 }, (_, i) => Array.from({ length: 10 }, (_, j) => i + j));
    while (true) {
        grid = updateGrid(grid);
    }
}

simulate();