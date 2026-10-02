function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
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
            if ((grid[i][j] && (neighbors === 2 || neighbors === 3)) || (!grid[i][j] && neighbors === 3)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        grid = updateGrid(grid);
        grid.forEach(row => {
            console.log(row.map(cell => cell ? '█' : ' ').join(''));
        });
        console.log();
    }
}

main();