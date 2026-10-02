function initialize_grid(size) {
    const random = require('random');
    const grid = [];
    for (let i = 0; i < size; i++) {
        const row = [];
        for (let j = 0; j < size; j++) {
            row.push(random.int(0, 1));
        }
        grid.push(row);
    }
    return grid;
}

function update_grid(grid) {
    const size = grid.length;
    const new_grid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < size && y >= 0 && y < size && !(x === i && y === j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return new_grid;
}

function main() {
    const size = 5;
    let grid = initialize_grid(size);
    for (let _ = 0; _ < 10; _++) {
        grid = update_grid(grid);
    }
    grid.forEach(row => console.log(row.join(' ')));
}

main();