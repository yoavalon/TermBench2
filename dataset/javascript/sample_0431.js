function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = grid.map(row => row.slice());
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let aliveNeighbors = 0;
            for (let ni = -1; ni <= 1; ni++) {
                for (let nj = -1; nj <= 1; nj++) {
                    const ii = i + ni;
                    const jj = j + nj;
                    if (ii >= 0 && ii < rows && jj >= 0 && jj < cols) {
                        aliveNeighbors += grid[ii][jj];
                    }
                }
            }
            aliveNeighbors -= grid[i][j];
            if (grid[i][j] === 1 && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && aliveNeighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(gridSize) {
    const grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = updateGrid(grid);
        console.log(grid.map(row => row.join(' ')).join('\n'));
    }
}

simulate(10);