function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
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
            newGrid[i][j] = grid[i][j] ? (neighbors >= 2 && neighbors <= 3 ? 1 : 0) : (neighbors === 3 ? 1 : 0);
        }
    }
    return newGrid;
}

function simulate(grid: number[][]): void {
    while (true) {
        grid = updateGrid(grid);
    }
}

function main(): void {
    const initialGrid: number[][] = [
        [0, 1, 0],
        [0, 1, 0],
        [0, 1, 0]
    ];
    simulate(initialGrid);
}

main();