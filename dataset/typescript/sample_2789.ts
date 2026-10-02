function cellularAutomata() {
    const random = Math.random;
    let grid = Array.from({ length: 100 }, () => Math.round(random()));
    while (true) {
        let newGrid = [];
        for (let i = 0; i < grid.length; i++) {
            let left = grid[i - 1], center = grid[i], right = grid[(i + 1) % grid.length];
            newGrid.push((left + center + right === 2) ? 1 : 0);
        }
        grid = newGrid;
    }
}
cellularAutomata();