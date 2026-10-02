function updateGrid(grid) {
    let newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = [];
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x !== 0 || y !== 0) {
                        neighbors.push([i + x, j + y]);
                    }
                }
            }
            let liveNeighbors = neighbors.reduce((sum, [x, y]) => {
                return sum + (grid[x] && grid[x][y] ? 1 : 0);
            }, 0);
            if (grid[i][j] && (liveNeighbors === 2 || liveNeighbors === 3)) {
                newGrid[i][j] = 1;
            } else if (!grid[i][j] && liveNeighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(grid) {
    display(grid);
    simulate(updateGrid(grid));
}

function display(grid) {
    console.log(grid.map(row => row.map(cell => cell ? '█' : ' ').join('')).join('\n'));
}

function main() {
    let initialGrid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initialGrid);
}

main();