function initializeGrid(rows: number, cols: number): number[][] {
    return Array.from({ length: rows }, () => Array(cols).fill(0));
}

function updateGrid(grid: number[][]): number[][] {
    const newGrid = grid.map(row => [...row]);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && !(x === i && y === j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = neighbors === 3 ? 1 : neighbors < 2 || neighbors > 3 ? 0 : grid[i][j];
        }
    }
    return newGrid;
}

function main() {
    const rows = 50, cols = 50;
    let grid = initializeGrid(rows, cols);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();