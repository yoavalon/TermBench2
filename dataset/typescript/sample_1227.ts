function cellularAutomata(size: number, steps: number): number[][] {
    let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let _ = 0; _ < steps; _++) {
        let newGrid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                let neighbors = 0;
                for (let dx of [-1, 0, 1]) {
                    for (let dy of [-1, 0, 1]) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
                neighbors -= grid[i][j];
                newGrid[i][j] = neighbors === 3 || (grid[i][j] && neighbors === 2) ? 1 : 0;
            }
        }
        grid = newGrid;
    }
    return grid;
}

cellularAutomata(10, 5);