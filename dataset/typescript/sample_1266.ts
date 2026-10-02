function cellularAutomata(n: number, m: number, steps: number): number[][] {
    const grid: number[][] = Array.from({ length: n }, () => Array(m).fill(0).map(() => Math.floor(Math.random() * 2)));
    for (let _ = 0; _ < steps; _++) {
        const newGrid: number[][] = grid.map(row => [...row]);
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                let neighbors = 0;
                for (let ni = Math.max(i - 1, 0); ni < Math.min(i + 2, n); ni++) {
                    for (let nj = Math.max(j - 1, 0); nj < Math.min(j + 2, m); nj++) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
                newGrid[i][j] = neighbors === 3 || (neighbors === 2 && grid[i][j]) ? 1 : 0;
            }
        }
        grid.splice(0, grid.length, ...newGrid);
    }
    return grid;
}

cellularAutomata(10, 10, 5);