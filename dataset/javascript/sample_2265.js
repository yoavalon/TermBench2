function updateGrid(grid, size) {
    let newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            let neighbors = [];
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    neighbors.push(grid[x][y]);
                }
            }
            let neighborsSum = neighbors.reduce((a, b) => a + b, 0) - grid[i][j];
            if (grid[i][j] === 0 && neighborsSum > 2) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] === 1 && (neighborsSum < 2 || neighborsSum > 3)) {
                newGrid[i][j] = 0;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    return newGrid;
}

function main() {
    let size = 50;
    let grid = Array.from({ length: size }, () => Array(size).fill(0));
    grid[size // 2][size // 2] = 1;
    while (true) {
        grid = updateGrid(grid, size);
    }
}

main();