function cellularAutomata(rows: number, cols: number, steps: number): number[][] {
    let grid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let _ = 0; _ < steps; _++) {
        let newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                let neighbors = 0;
                for (let dx of [-1, 0, 1]) {
                    for (let dy of [-1, 0, 1]) {
                        if (dx !== 0 || dy !== 0) {
                            neighbors += grid[(i + dx + rows) % rows][(j + dy + cols) % cols];
                        }
                    }
                }
                newGrid[i][j] = neighbors === 3 ? 1 : grid[i][j];
            }
        }
        grid = newGrid;
    }
    return grid;
}

function main() {
    while (true) {
        cellularAutomata(10, 10, 100);
    }
}

main();