import { zeros } from 'numpy';

function initializeGrid(size: number): number[][] {
    let grid: number[][] = zeros([size, size]) as number[][];
    grid[size // 2][size // 2] = 1;
    return grid;
}

function applyBoundaryConditions(grid: number[][]): void {
    let size = grid.length;
    for (let i = 0; i < size; i++) {
        grid[0][i] = 0;
        grid[size - 1][i] = 0;
        grid[i][0] = 0;
        grid[i][size - 1] = 0;
    }
}

function updateGrid(grid: number[][]): number[][] {
    let newGrid: number[][] = grid.map(row => [...row]);
    let size = grid.length;
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                }
            } else if (neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(steps: number): number[][] {
    let size = 50;
    let grid: number[][] = initializeGrid(size);
    applyBoundaryConditions(grid);
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
        applyBoundaryConditions(grid);
    }
    return grid;
}

function main(): void {
    let steps = 100;
    let result: number[][] = simulate(steps);
    console.log(result);
}

main();