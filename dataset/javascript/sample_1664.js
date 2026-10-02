function initGrid(size) {
    let grid = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.floor(Math.random() * 2));
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid) {
    let newGrid = JSON.parse(JSON.stringify(grid));
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[0].length - 1; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x !== 0 || y !== 0) {
                        neighbors += grid[i + x][j + y];
                    }
                }
            }
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (!grid[i][j] && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let size = 10;
    let grid = initGrid(size);
    while (true) {
        grid = updateGrid(grid);
        console.log(grid);
        console.log('-'.repeat(40));
    }
}

main();