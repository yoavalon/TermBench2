function initializeGrid(size: number): number[][] {
    const grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[size // 2][size // 2] = 1;
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    const newSize = grid.length;
    const newGrid: number[][] = Array.from({ length: newSize }, () => Array(newSize).fill(0));
    for (let i = 0; i < newSize; i++) {
        for (let j = 0; j < newSize; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(newSize, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(newSize, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (neighbors === 3 || (grid[i][j] === 1 && neighbors === 2)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 10;
    let grid = initializeGrid(gridSize);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();