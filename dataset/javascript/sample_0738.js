function updateGrid(grid, size) {
    let newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = (neighbors === 3 || (neighbors === 2 && grid[i][j])) ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid, size, steps) {
    if (steps === 0) {
        return grid;
    }
    return simulate(updateGrid(grid, size), size, steps - 1);
}

function main() {
    let size = 10;
    let initialGrid = Array.from({ length: size }, () => Array(size).fill(0));
    initialGrid[5][5] = 1;
    initialGrid[5][6] = 1;
    initialGrid[6][5] = 1;
    initialGrid[6][6] = 1;
    let finalGrid = simulate(initialGrid, size, 10);
    finalGrid.forEach(row => console.log(row.join(' ')));
}

main();