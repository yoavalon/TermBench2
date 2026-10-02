function update_cell(state, neighbors) {
    let active_neighbors = neighbors.reduce((a, b) => a + b, 0);
    if (state === 1) {
        return active_neighbors === 2 || active_neighbors === 3 ? 1 : 0;
    } else {
        return active_neighbors === 3 ? 1 : 0;
    }
}

function simulate(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let new_grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = [];
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) continue;
                    let ni = i + x;
                    let nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors.push(grid[ni][nj]);
                    }
                }
            }
            new_grid[i][j] = update_cell(grid[i][j], neighbors);
        }
    }
    return new_grid;
}

function main() {
    let grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]];
    while (true) {
        grid = simulate(grid);
    }
}

main();