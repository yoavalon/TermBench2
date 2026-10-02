function initGrid(size) {
    return Array.from({ length: size }, (_, y) =>
        Array.from({ length: size }, (_, x) => (x !== 0 && x !== size - 1 && y !== 0 && y !== size - 1 ? 0 : 1))
    );
}

function updateGrid(grid) {
    const newGrid = grid.map(row => [...row]);
    for (let y = 1; y < grid.length - 1; y++) {
        for (let x = 1; x < grid[0].length - 1; x++) {
            const neighbors = [
                grid[y - 1][x],
                grid[y + 1][x],
                grid[y][x - 1],
                grid[y][x + 1]
            ];
            newGrid[y][x] = neighbors.reduce((sum, val) => sum + val, 0) >= 2 ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid) {
    while (true) {
        grid = updateGrid(grid);
    }
}

function main() {
    const size = 10;
    const grid = initGrid(size);
    simulate(grid);
}

main();