function update_grid(grid, rules) {
    let new_grid = grid.map(row => [...row]);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            neighbors -= grid[i][j];
            new_grid[i][j] = rules[neighbors];
        }
    }
    return new_grid;
}

function simulate(grid, rules) {
    const os = require('os');
    const clearCommand = os.platform() === 'win32' ? 'cls' : 'clear';
    require('child_process').execSync(clearCommand);
    for (let row of grid) {
        console.log(row.map(cell => cell ? '#' : '.').join(''));
    }
    simulate(update_grid(grid, rules), rules);
}

function main() {
    let width = 20;
    let height = 20;
    let initial_grid = Array.from({ length: height }, (_, i) => Array.from({ length: width }, (_, j) => (i + j) % 2 === 0 ? 1 : 0));
    let rules = [0, 0, 1, 1, 0, 0, 0, 0, 0];
    simulate(initial_grid, rules);
}

main();