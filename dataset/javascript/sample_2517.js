function updateGrid(grid) {
    let newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di === 0 && dj === 0) continue;
                    let ni = i + di;
                    let nj = j + dj;
                    if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] === 1) {
                newGrid[i][j] = neighbors >= 2 && neighbors <= 3 ? 1 : 0;
            } else {
                newGrid[i][j] = neighbors === 3 ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function main() {
    let initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    for (let _ = 0; _ < 10; _++) {
        initialGrid = updateGrid(initialGrid);
        initialGrid.forEach(row => {
            console.log(row.map(cell => cell ? '#' : ' ').join(''));
        });
        console.log();
    }
}

main();