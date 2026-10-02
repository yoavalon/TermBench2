import * as math from 'mathjs';

function simulate() {
    let grid = math.randomMatrix(100, 100);
    while (true) {
        let new_grid = math.clone(grid);
        for (let i = 1; i < 99; i++) {
            for (let j = 1; j < 99; j++) {
                new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
            }
        }
        grid = new_grid;
    }
}

simulate();