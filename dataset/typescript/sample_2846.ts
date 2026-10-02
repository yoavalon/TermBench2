import { random } from 'lodash';

function generateGrid(size: number): number[][] {
    return Array.from({ length: size }, () => Array.from({ length: size }, () => random(0, 1)));
}

function updateGrid(grid: number[][]): number[][] {
    const size = grid.length;
    const newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let dx of [-1, 0, 1]) {
                for (let dy of [-1, 0, 1]) {
                    if (dx !== 0 || dy !== 0) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
            }
            if (grid[i][j] && (neighbors === 2 || neighbors === 3) || (!grid[i][j] && neighbors === 3)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 10;
    let grid = generateGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();