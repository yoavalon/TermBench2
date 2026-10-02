function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if ((x !== i || y !== j) && x >= 0 && x < rows && y >= 0 && y < cols) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if ((grid[i][j] === 1 && (neighbors === 2 || neighbors === 3)) || (grid[i][j] === 0 && neighbors === 3)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let grid: number[][] = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        grid = updateGrid(grid);
        for (const row of grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

main();