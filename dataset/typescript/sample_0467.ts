function initialize_grid(size: number): number[][] {
    return Array.from({ length: size }, () => Array(size).fill(0));
}

function update_grid(grid: number[][]): number[][] {
    const new_grid = grid.map(row => [...row]);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) continue;
                    const ni = i + x;
                    const nj = j + y;
                    if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[i].length) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : 0;
        }
    }
    return new_grid;
}

function main() {
    const grid_size = 10;
    let grid = initialize_grid(grid_size);
    while (true) {
        grid = update_grid(grid);
    }
}

main();