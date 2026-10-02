function update_grid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid = Array.from({ length: rows }, () => Array(cols).fill(0));
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
            if (grid[i][j] === 1 && (neighbors === 2 || neighbors === 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

function simulate(grid) {
    print_grid(grid);
    simulate(update_grid(grid));
}

function print_grid(grid) {
    for (const row of grid) {
        console.log(row.map(cell => cell ? 'O' : ' ').join(''));
    }
    console.log();
}

function main() {
    const initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    simulate(initial_grid);
}

main();