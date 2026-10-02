function update_state(grid) {
    let new_grid = grid.map(row => [...row]);
    for (let y = 0; y < grid.length; y++) {
        for (let x = 0; x < grid[y].length; x++) {
            let neighbors = [];
            for (let dy = -1; dy <= 1; dy++) {
                for (let dx = -1; dx <= 1; dx++) {
                    if (dy === 0 && dx === 0) continue;
                    let ny = y + dy, nx = x + dx;
                    if (ny >= 0 && ny < grid.length && nx >= 0 && nx < grid[y].length) {
                        neighbors.push(grid[ny][nx]);
                    }
                }
            }
            let count = neighbors.reduce((sum, cell) => sum + cell, 0);
            if (grid[y][x] === 1 && count < 2) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] === 1 && (count === 2 || count === 3)) {
                new_grid[y][x] = 1;
            } else if (grid[y][x] === 1 && count > 3) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] === 0 && count === 3) {
                new_grid[y][x] = 1;
            }
        }
    }
    return new_grid;
}

function display_grid(grid) {
    grid.forEach(row => {
        console.log(row.map(cell => cell ? 'O' : ' ').join(''));
    });
    console.log();
}

function simulate(grid) {
    display_grid(grid);
    simulate(update_state(grid));
}

function main() {
    let initial_grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initial_grid);
}

main();