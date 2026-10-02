function updateState(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            const neighbors = [
                grid[r - 1]?.[c], grid[r + 1]?.[c], grid[r]?.[c - 1], grid[r]?.[c + 1]
            ].filter(cell => cell !== undefined);
            newGrid[r][c] = neighbors.filter(cell => cell === 1).length === 3 ? 1 : grid[r][c];
        }
    }
    return newGrid;
}

function runSimulation() {
    let grid = [
        [0, 1, 0],
        [0, 1, 0],
        [0, 1, 0]
    ];
    while (true) {
        grid = updateState(grid);
        for (const row of grid) {
            console.log(row.map(cell => cell ? 'O' : ' ').join(''));
        }
        console.log();
    }
}

runSimulation();