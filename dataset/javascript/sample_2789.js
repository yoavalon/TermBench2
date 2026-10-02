function cellular_automata() {
    const random = Math.random;
    let grid = Array(100).fill().map(() => Math.round(random()));
    while (true) {
        let new_grid = [];
        for (let i = 0; i < grid.length; i++) {
            let left = grid[(i - 1 + grid.length) % grid.length];
            let center = grid[i];
            let right = grid[(i + 1) % grid.length];
            new_grid.push(left + center + right === 2 ? 1 : 0);
        }
        grid = new_grid;
    }
}

cellular_automata();