const updateGrid = (grid) => {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di === 0 && dj === 0) continue;
                    const ni = i + di;
                    const nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            newGrid[i][j] = (neighbors === 3) || (neighbors === 2 && grid[i][j]) ? 1 : 0;
        }
    }
    return newGrid;
};

const main = () => {
    const grid = Array.from({ length: 50 }, () => Array(50).fill(0));
    grid[25][25] = 1;
    while (true) {
        grid = updateGrid(grid);
    }
};

main();