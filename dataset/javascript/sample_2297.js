function initGrid(size) {
    return Array.from({ length: size }, () => Array(size).fill(0.0));
}

function updateGrid(grid, diffusionRate) {
    const size = grid.length;
    const newGrid = initGrid(size);
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0.0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di === 0 && dj === 0) continue;
                    const ni = i + di;
                    const nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            newGrid[i][j] = grid[i][j] + diffusionRate * neighbors;
        }
    }
    return newGrid;
}

function main() {
    const size = 100;
    const diffusionRate = 0.01;
    let grid = initGrid(size);
    while (true) {
        grid = updateGrid(grid, diffusionRate);
    }
}

main();