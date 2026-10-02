import * as math from 'mathjs';

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 1; i < rows - 1; i++) {
        for (let j = 1; j < cols - 1; j++) {
            let sum = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    sum += grid[i + x][j + y];
                }
            }
            newGrid[i][j] = sum - grid[i][j];
        }
    }
    return newGrid;
}

function simulateFlow(iterations: number): number[][] {
    const grid: number[][] = Array.from({ length: 10 }, () => Array(10).fill(0).map(() => Math.random()));
    for (let _ = 0; _ < iterations; _++) {
        grid = updateGrid(grid);
    }
    return grid;
}

function main() {
    const result = simulateFlow(100);
    console.log(result);
}

main();