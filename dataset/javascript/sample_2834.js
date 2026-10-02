function update_state(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let new_grid = grid.map(row => row.slice());
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    let ni = i + di;
                    let nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors === 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

function main() {
    let size = 100;
    let grid = Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = update_state(grid);
    }
}

main();