function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && (x !== i || y !== j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = neighbors === 3 || (neighbors === 2 && grid[i][j] === 1) ? 1 : 0;
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
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initialGrid);
}

main();