function update_cells(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let new_grid = Array(rows).fill().map(() => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : grid[i][j];
        }
    }
    return new_grid;
}

function display_grid(grid) {
    for (let row of grid) {
        console.log(row.map(cell => cell ? 'O' : '.').join(' '));
    }
}

function main() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        display_grid(grid);
        grid = update_cells(grid);
    }
}

main();