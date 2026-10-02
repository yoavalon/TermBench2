function main() {
    const { zeros, roll } = require('numpy');

    function update(grid) {
        return (grid + roll(grid, 1, 0) + roll(grid, -1, 0) + roll(grid, 1, 1) + roll(grid, -1, 1)) % 2;
    }

    let grid = zeros([100, 100], 'int');
    grid[50][50] = 1;
    while (true) {
        grid = update(grid);
    }
}

main();