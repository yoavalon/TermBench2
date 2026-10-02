function update_grid(grid) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let count = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && (x !== i || y !== j)) {
                        count += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = grid[i][j] && (count === 2 || count === 3) ? 1 : count === 3;
        }
    }
    return new_grid;
}

function simulate(grid, steps) {
    for (let _ = 0; _ < steps; _++) {
        grid = update_grid(grid);
    }
    return grid;
}

function main() {
    let initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]];
    let final_grid = simulate(initial_grid, 10);
    final_grid.forEach(row => console.log(row));
}

main();