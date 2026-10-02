function initializeGrid(size) {
    let grid = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            row.push(0);
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid) {
    let newGrid = [];
    for (let i = 0; i < grid.length; i++) {
        let newRow = grid[i].slice();
        for (let j = 0; j < grid[i].length; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) {
                        continue;
                    }
                    let ni = i + x;
                    let nj = j + y;
                    if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[i].length) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            newRow[j] = neighbors === 3 ? 1 : 0;
        }
        newGrid.push(newRow);
    }
    return newGrid;
}

function main() {
    let gridSize = 10;
    let grid = initializeGrid(gridSize);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();