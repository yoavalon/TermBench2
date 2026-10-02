const random = require('random');

function simulate() {
    const gridSize = 30;
    let grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0));
    while (true) {
        let newGrid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0));
        for (let i = 0; i < gridSize; i++) {
            for (let j = 0; j < gridSize; j++) {
                let neighbors = 0;
                for (let x of [-1, 0, 1]) {
                    for (let y of [-1, 0, 1]) {
                        if (x !== 0 || y !== 0) {
                            neighbors += grid[(i + x + gridSize) % gridSize][(j + y + gridSize) % gridSize];
                        }
                    }
                }
                if ((grid[i][j] && neighbors >= 2 && neighbors <= 3) || (!grid[i][j] && neighbors === 3)) {
                    newGrid[i][j] = 1;
                }
            }
        }
        grid = newGrid;
    }
}

simulate();