function cellular_automata(grid, rule) {
    let new_grid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = [];
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x !== 0 || y !== 0) {
                        neighbors.push(grid[(i + x) % grid.length][(j + y) % grid[0].length]);
                    }
                }
            }
            new_grid[i][j] = rule([...neighbors].sort().join(''));
        }
    }
    return cellular_automata(new_grid, rule);
}

function main() {
    let initial_grid = Array.from({ length: 10 }, (_, i) => Array(10).fill(0).map((_, j) => i === j ? 1 : 0));
    let rule = n => n === '111' ? 1 : 0;
    cellular_automata(initial_grid, rule);
}

main();