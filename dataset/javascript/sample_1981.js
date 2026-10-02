function update_state(grid) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0.0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) continue;
                    let ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = neighbors / 9.0;
        }
    }
    return new_grid;
}

function run_simulation(steps, size) {
    let grid = Array.from({ length: size }, (_, i) => Array(size).fill(i === 0 ? 1.0 : 0.0));
    for (let _ = 0; _ < steps; _++) {
        grid = update_state(grid);
    }
    return grid;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = run_simulation(10, 5);
    result.forEach(row => console.log(row));
}