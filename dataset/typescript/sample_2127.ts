function cellularAutomata(n: number): void {
    let grid: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    while (true) {
        let nextGrid: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                let neighbors = 0;
                for (let x of [-1, 0, 1]) {
                    for (let y of [-1, 0, 1]) {
                        if (x === 0 && y === 0) continue;
                        neighbors += grid[(i + x + n) % n][(j + y + n) % n];
                    }
                }
                if (neighbors === 3 || (grid[i][j] === 1 && neighbors === 2)) {
                    nextGrid[i][j] = 1;
                }
            }
        }
        grid = nextGrid;
    }
}

cellularAutomata(10);