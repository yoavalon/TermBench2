function updateState(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            let neighbors = [];
            [[r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]].forEach(([x, y]) => {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    neighbors.push(grid[x][y]);
                }
            });
            newGrid[r][c] = neighbors.reduce((sum, cell) => sum + cell, 0) === 3 ? 1 : grid[r][c];
        }
    }
    return newGrid;
}

function runSimulation() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        grid = updateState(grid);
        grid.forEach(row => {
            console.log(row.map(cell => cell ? 'O' : ' ').join(''));
        });
        console.log();
    }
}
runSimulation();