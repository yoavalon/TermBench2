function update_grid(grid) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let neighbors = [];
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (!(x === 0 && y === 0)) {
                        neighbors.push([i + x, j + y]);
                    }
                }
            }
            let live_neighbors = neighbors.reduce((acc, [x, y]) => {
                if (x >= 0 && x < grid.length && y >= 0 && y < grid[i].length) {
                    return acc + grid[x][y];
                }
                return acc;
            }, 0);
            new_grid[i][j] = (live_neighbors === 3 || (grid[i][j] && live_neighbors === 2)) ? 1 : 0;
        }
    }
    return new_grid;
}

function main() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    for (let _ = 0; _ < 10; _++) {
        grid = update_grid(grid);
        console.log(grid.map(row => row.map(cell => cell ? 'X' : ' ').join('')).join('\n'));
        console.log();
    }
}

main();