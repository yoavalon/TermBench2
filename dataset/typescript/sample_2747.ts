function cellularAutomata(x: number, y: number, steps: number): void {
    let grid: number[][] = Array.from({ length: y }, () => Array(x).fill(0));
    for (let _ = 0; _ < steps; _++) {
        let newGrid: number[][] = grid.map(row => [...row]);
        for (let i = 0; i < y; i++) {
            for (let j = 0; j < x; j++) {
                let neighbors = 0;
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        if (0 <= i + di && i + di < y && 0 <= j + dj && j + dj < x) {
                            neighbors += grid[i + di][j + dj];
                        }
                    }
                }
                neighbors -= grid[i][j];
                newGrid[i][j] = neighbors === 3 || (neighbors === 2 && grid[i][j]) ? 1 : 0;
            }
        }
        grid = newGrid;
    }
}

function main(): void {
    cellularAutomata(10, 10, 1000000);
}

main();