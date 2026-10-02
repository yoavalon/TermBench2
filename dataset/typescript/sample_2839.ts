import { randomInt } from 'crypto';

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(i - 1, 0); ni < Math.min(i + 2, rows); ni++) {
                for (let nj = Math.max(j - 1, 0); nj < Math.min(j + 2, cols); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 10;
    const grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0).map(() => randomInt(2)));
    while (true) {
        grid.forEach(row => console.log(row.join(' ')));
        grid = updateGrid(grid);
    }
}

main();