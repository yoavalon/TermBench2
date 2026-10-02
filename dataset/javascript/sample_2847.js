const { random } = Math;

function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = grid.map(row => [...row]);
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = grid[i][(j - 1 + cols) % cols] + grid[i][(j + 1) % cols] + grid[(i - 1 + rows) % rows][j] + grid[(i + 1) % rows][j] + grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols] + grid[(i - 1 + rows) % rows][(j + 1) % cols] + grid[(i + 1) % rows][(j - 1 + cols) % cols] + grid[(i + 1) % rows][(j + 1) % cols];
            if (grid[i][j] === 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                }
            } else if (neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 10;
    const grid = Array.from({ length: gridSize }, () => Array.from({ length: gridSize }, () => Math.round(random())));
    while (true) {
        grid.forEach(row => console.log(row.join(' ')));
        console.log('-'.repeat(20));
        grid = updateGrid(grid);
    }
}

main();