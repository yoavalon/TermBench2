function cellularAutomata(x, y, steps) {
    let grid = Array.from({ length: y }, () => Array(x).fill(0));
    for (let _ = 0; _ < steps; _++) {
        let newGrid = grid.map(row => [...row]);
        for (let i = 0; i < y; i++) {
            for (let j = 0; j < x; j++) {
                let neighbors = 0;
                for (let di = -1; di < 2; di++) {
                    for (let dj = -1; dj < 2; dj++) {
                        if (0 <= i + di && i + di < y && 0 <= j + dj && j + dj < x) {
                            neighbors += grid[i + di][j + dj];
                        }
                    }
                }
                neighbors -= grid[i][j];
                newGrid[i][j] = (neighbors === 3 || (neighbors === 2 && grid[i][j])) ? 1 : 0;
            }
        }
        grid = newGrid;
    }
}

function main() {
    cellularAutomata(10, 10, 1000000);
}
main();