function initialize_grid(size) {
    const random = require('random');
    let grid = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            row.push(random.int(0, 1));
        }
        grid.push(row);
    }
    return grid;
}

function update_grid(grid) {
    let size = grid.length;
    let new_grid = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di !== 0 || dj !== 0) {
                        neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                    }
                }
            }
            row.push(neighbors === 3 || (grid[i][j] && neighbors === 2) ? 1 : 0);
        }
        new_grid.push(row);
    }
    return new_grid;
}

function simulate(steps, size) {
    let grid = initialize_grid(size);
    for (let _ = 0; _ < steps; _++) {
        grid = update_grid(grid);
    }
    return grid;
}

function main() {
    let steps = 10, size = 5;
    let result = simulate(steps, size);
    result.forEach(row => console.log(row.join(' ')));
}

main();