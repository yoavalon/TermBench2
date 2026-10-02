function cellular_automata(grid, x, y) {
    if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
        return 0;
    }
    return grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1);
}

function main() {
    let grid = Array.from({ length: 10 }, () => Array(10).fill(0));
    while (true) {
        for (let i = 0; i < grid.length; i++) {
            for (let j = 0; j < grid[0].length; j++) {
                grid[i][j] = cellular_automata(grid, i, j);
            }
        }
    }
}

main();