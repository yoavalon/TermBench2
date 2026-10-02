function updateGrid(grid) {
    let rows = grid.length;
    let cols = grid[0].length;
    let newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = neighbors === 3 ? 1 : grid[i][j] && neighbors === 2 ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid) {
    simulate(updateGrid(grid));
}

function main() {
    let gridSize = 10;
    let initialGrid = Array.from({ length: gridSize }, (_, i) =>
        Array.from({ length: gridSize }, (_, j) => (i % 2 === 0 || j % 2 === 0 ? 0 : 1))
    );
    simulate(initialGrid);
}

main();