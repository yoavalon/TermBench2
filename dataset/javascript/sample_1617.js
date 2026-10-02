function updateState(grid) {
    let newGrid = grid.map(row => [...row]);
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let size = 50;
    let grid = Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = updateState(grid);
    }
}

main();