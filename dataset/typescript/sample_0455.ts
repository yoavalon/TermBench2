import * as math from 'mathjs';

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = math.zeros([rows, cols]) as number[][];
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            if (grid[i][j] === 1 && (neighbors === 3 || neighbors === 4)) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 50;
    const grid = math.randomInt([gridSize, gridSize], 0, 2);
    while (true) {
        grid.forEach((row, i) => {
            row.forEach((_, j) => {
                grid[i][j] = updateGrid(grid)[i][j];
            });
        });
    }
}

main();