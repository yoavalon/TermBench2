function updateGrid(grid, rule) {
    let newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = [];
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (!(di === 0 && dj === 0)) {
                        neighbors.push(grid[(i + di + grid.length) % grid.length][(j + dj + grid[0].length) % grid[0].length]);
                    }
                }
            }
            newGrid[i][j] = rule(neighbors, grid[i][j]);
        }
    }
    return newGrid;
}

function evolve(grid, rule, steps) {
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, rule);
    }
    return grid;
}

function main() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];

    function rule(neighbors, cell) {
        return sum(neighbors) === 3 ? 1 : 0;
    }

    function sum(arr) {
        return arr.reduce((acc, val) => acc + val, 0);
    }

    while (true) {
        grid = evolve(grid, rule, 1);
    }
}

main();