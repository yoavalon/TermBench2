function update_grid(grid) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = [
                grid[(i - 1 + grid.length) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                grid[(i - 1 + grid.length) % grid.length][j],
                grid[(i - 1 + grid.length) % grid.length][(j + 1) % grid[0].length],
                grid[i][(j - 1 + grid[0].length) % grid[0].length],
                grid[i][(j + 1) % grid[0].length],
                grid[(i + 1) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                grid[(i + 1) % grid.length][j],
                grid[(i + 1) % grid.length][(j + 1) % grid[0].length]
            ];
            new_grid[i][j] = Math.floor(neighbors.reduce((a, b) => a + b, 0) / 2);
        }
    }
    return new_grid;
}

function simulate(grid) {
    while (true) {
        grid = update_grid(grid);
        for (let row of grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

function main() {
    let initial_grid = [[1, 0, 1], [0, 1, 0], [1, 0, 1]];
    simulate(initial_grid);
}

main();