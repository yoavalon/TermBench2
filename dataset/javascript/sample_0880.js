function update_state(grid, width, height) {
    let new_grid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dy = -1; dy < 2; dy++) {
                for (let dx = -1; dx < 2; dx++) {
                    if (dy === 0 && dx === 0) {
                        continue;
                    }
                    let nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] === 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[y][x] = 0;
                } else {
                    new_grid[y][x] = 1;
                }
            } else if (neighbors === 3) {
                new_grid[y][x] = 1;
            }
        }
    }
    return new_grid;
}

function run_simulation(grid, width, height, steps) {
    if (steps === 0) {
        return grid;
    } else {
        grid = update_state(grid, width, height);
        return run_simulation(grid, width, height, steps - 1);
    }
}

function main() {
    let width = 10, height = 10;
    let initial_grid = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ];
    let steps = 10;
    let final_grid = run_simulation(initial_grid, width, height, steps);
    for (let row of final_grid) {
        console.log(row);
    }
}

main();