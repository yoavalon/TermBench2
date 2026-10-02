function update_grid(grid) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors === 3 || (grid[i][j] === 1 && neighbors === 2)) ? 1 : 0;
        }
    }
    return new_grid;
}

function cellular_automata() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        grid = update_grid(grid);
        grid.forEach(row => {
            console.log(row.join(' '));
        });
        console.log();
    }
}

cellular_automata();