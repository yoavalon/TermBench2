const { random } = Math;

function generateGrid(size) {
    return Array.from({ length: size }, () => Array.from({ length: size }, () => random() < 0.5 ? 0 : 1));
}

function updateGrid(grid) {
    const size = grid.length;
    const newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let dx = -1; dx <= 1; dx++) {
                for (let dy = -1; dy <= 1; dy++) {
                    if (dx === 0 && dy === 0) continue;
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            if ((grid[i][j] && (neighbors === 2 || neighbors === 3)) || (!grid[i][j] && neighbors === 3)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 10;
    let grid = generateGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();