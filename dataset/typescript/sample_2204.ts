function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0.0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let total = 0.0;
            for (let di of [-1, 0, 1]) {
                for (let dj of [-1, 0, 1]) {
                    const ni = i + di;
                    const nj = j + dj;
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
    let grid: number[][] = Array.from({ length: 10 }, (_, i) => Array.from({ length: 10 }, (_, j) => i + j));
    while (true) {
        grid = updateGrid(grid);
    }
}

simulate();