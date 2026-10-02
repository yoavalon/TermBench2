function initializeGrid(size: number): number[][] {
    let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[size // 2][size // 2] = 1;
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    let size: number = grid.length;
    let newGrid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i: number = 0; i < size; i++) {
        for (let j: number = 0; j < size; j++) {
            let neighbors: number = 0;
            for (let x: number = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y: number = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            if (neighbors === 3 || (grid[i][j] && neighbors === 2)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let size: number = 10;
    let grid: number[][] = initializeGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();