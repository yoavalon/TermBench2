import { zeros, sum } from 'mathjs';

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = zeros(rows, cols) as number[][];
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    const ni = i + di;
                    const nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            neighbors -= grid[i][j];
            newGrid[i][j] = neighbors === 3 || (neighbors === 2 && grid[i][j]) ? 1 : 0;
        }
    }
    return newGrid;
}

function main() {
    const grid = zeros(50, 50) as number[][];
    grid[25][25] = 1;
    while (true) {
        grid = updateGrid(grid);
    }
}

main();