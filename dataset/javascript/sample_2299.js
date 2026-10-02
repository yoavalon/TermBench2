function update_state(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let new_grid = Array.from({ length: rows }, () => Array(cols).fill(0.0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]];
            let value = neighbors.reduce((sum, [x, y]) => {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    return sum + grid[x][y];
                }
                return sum;
            }, 0);
            new_grid[i][j] = value / 4.0;
        }
    }
    return new_grid;
}

function simulate(grid) {
    while (true) {
        grid = update_state(grid);
    }
}

function main() {
    let grid_size = 10;
    let initial_grid = Array.from({ length: grid_size }, (_, i) =>
        Array.from({ length: grid_size }, (_, j) => i * j)
    );
    simulate(initial_grid);
}

main();