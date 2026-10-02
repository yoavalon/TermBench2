function updateGrid(grid) {
    let size = grid.length;
    let newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = [
                grid[(i - 1 + size) % size][(j - 1 + size) % size],
                grid[(i - 1 + size) % size][j],
                grid[(i - 1 + size) % size][(j + 1) % size],
                grid[i][(j - 1 + size) % size],
                grid[i][(j + 1) % size],
                grid[(i + 1) % size][(j - 1 + size) % size],
                grid[(i + 1) % size][j],
                grid[(i + 1) % size][(j + 1) % size]
            ];
            let liveNeighbors = neighbors.reduce((acc, val) => acc + val, 0);
            if (grid[i][j]) {
                newGrid[i][j] = liveNeighbors === 2 || liveNeighbors === 3 ? 1 : 0;
            } else {
                newGrid[i][j] = liveNeighbors === 3 ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function main() {
    let size = 10;
    let grid = Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = updateGrid(grid);
        grid.forEach(row => {
            console.log(row.join(' '));
        });
        console.log();
    }
}

main();