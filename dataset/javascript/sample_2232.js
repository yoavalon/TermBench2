function initializeGrid(size) {
    const grid = [];
    for (let i = 0; i < size; i++) {
        const row = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.floor(Math.random() * 2));
        }
        grid.push(row);
    }
    return grid;
}

function evolve(grid) {
    const size = grid.length;
    const nextGrid = [];
    for (let i = 0; i < size; i++) {
        const row = [];
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di === 0 && dj === 0) continue;
                    const ni = (i + di + size) % size;
                    const nj = (j + dj + size) % size;
                    neighbors += grid[ni][nj];
                }
            }
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                row.push(0);
            } else if (grid[i][j] === 0 && neighbors === 3) {
                row.push(1);
            } else {
                row.push(grid[i][j]);
            }
        }
        nextGrid.push(row);
    }
    return nextGrid;
}

function main() {
    const gridSize = 100;
    let grid = initializeGrid(gridSize);
    while (true) {
        grid = evolve(grid);
    }
}

main();