function initializeGrid(size) {
    const grid = [];
    for (let i = 0; i < size; i++) {
        const row = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.random() < 0.5 ? 0 : 1);
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid) {
    const size = grid.length;
    const newGrid = [];
    for (let i = 0; i < size; i++) {
        const row = [];
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let dx = -1; dx <= 1; dx++) {
                for (let dy = -1; dy <= 1; dy++) {
                    if (dx === 0 && dy === 0) continue;
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            row.push(neighbors === 3 ? 1 : neighbors === 2 ? grid[i][j] : 0);
        }
        newGrid.push(row);
    }
    return newGrid;
}

function main() {
    let grid = initializeGrid(10);
    while (true) {
        grid = updateGrid(grid);
        grid.forEach(row => console.log(row.map(cell => cell ? 'O' : ' ').join('')));
        console.log();
    }
}

main();