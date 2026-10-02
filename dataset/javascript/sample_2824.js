function init_grid(rows, cols) {
    let grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    grid[Math.floor(rows / 2)][Math.floor(cols / 2)] = 1;
    return grid;
}

function update_grid(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let new_grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]].forEach(([x, y]) => {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    neighbors += grid[x][y];
                }
            });
            new_grid[i][j] = neighbors === 1 ? 1 : 0;
        }
    }
    return new_grid;
}

function main() {
    let grid = init_grid(10, 10);
    while (true) {
        grid = update_grid(grid);
    }
}

main();