function update_grid(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let new_grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && (x !== i || y !== j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors === 3 || (neighbors === 2 && grid[i][j] === 1)) ? 1 : 0;
        }
    }
    return new_grid;
}

function simulate(grid) {
    while (true) {
        grid = update_grid(grid);
    }
}

function main() {
    let initial_grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initial_grid);
}

main();