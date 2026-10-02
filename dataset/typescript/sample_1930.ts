import * as math from 'mathjs';

function updateGrid(grid: number[][], precision: number): number[][] {
    const size = grid.length;
    const newGrid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            const avg = math.mean(grid.slice(i - 1, i + 2).flatMap(row => row.slice(j - 1, j + 2)));
            newGrid[i][j] = math.round(avg, precision);
        }
    }
    return newGrid;
}

function runSimulation(steps: number, precision: number): number[][] {
    const gridSize = 10;
    const grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0).map(() => Math.random()));
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, precision);
    }
    return grid;
}

if (require.main === module) {
    const steps = 50;
    const precision = 3;
    const result = runSimulation(steps, precision);
    console.log(result);
}