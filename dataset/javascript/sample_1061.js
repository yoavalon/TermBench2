function update_grid(grid) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = [];
            for (let di = -1; di < 2; di++) {
                for (let dj = -1; dj < 2; dj++) {
                    if (i + di >= 0 && i + di < grid.length && j + dj >= 0 && j + dj < grid[0].length) {
                        neighbors.push(grid[i + di][j + dj]);
                    }
                }
            }
            new_grid[i][j] = Math.floor(neighbors.reduce((a, b) => a + b, 0) / neighbors.length);
        }
    }
    return new_grid;
}

function display(grid) {
    for (let row of grid) {
        console.log(row.join(' '));
    }
    console.log();
}

function simulate(grid) {
    display(grid);
    simulate(update_grid(grid));
}

function main() {
    let grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]];
    simulate(grid);
}

main();