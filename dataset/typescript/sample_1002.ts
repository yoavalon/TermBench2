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
            if (grid[i][j] === 1 && (neighbors === 2 || neighbors === 3)) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(grid: number[][]): void {
    printGrid(grid);
    simulate(updateGrid(grid));
}

function printGrid(grid: number[][]): void {
    for (const row of grid) {
        console.log(row.map(cell => cell ? 'O' : ' ').join(''));
    }
    console.log();
}

function main(): void {
    const initialGrid: number[][] = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    simulate(initialGrid);
}

main();