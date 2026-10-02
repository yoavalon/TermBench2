function initializeGrid(size: number): number[][] {
    let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[size // 2][size // 2] = 1;
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    let size = grid.length;
    let newGrid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = neighbors === 3 ? 1 : 0;
        }
    }
    return newGrid;
}

function main() {
    let size = 10;
    let grid = initializeGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();