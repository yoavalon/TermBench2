function cellularAutomata(grid, steps) {
    for (let _ = 0; _ < steps; _++) {
        let newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
        for (let i = 0; i < grid.length; i++) {
            for (let j = 0; j < grid[0].length; j++) {
                let neighbors = 0;
                for (let [x, y] of [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]) {
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                        neighbors += grid[x][y];
                    }
                }
                newGrid[i][j] = (neighbors === 2 || (neighbors === 3 && grid[i][j] === 1)) ? 1 : 0;
            }
        }
        grid = newGrid;
    }
    return grid;
}

let initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
let steps = 5;
let result = cellularAutomata(initialGrid, steps);
console.log(result);