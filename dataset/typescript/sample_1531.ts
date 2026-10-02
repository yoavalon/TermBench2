function cellular_automata(width: number, height: number): void {
    const grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    while (true) {
        const new_grid: number[][] = grid.map(row => [...row]);
        for (let i = 1; i < height - 1; i++) {
            for (let j = 1; j < width - 1; j++) {
                let neighbors = 0;
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        neighbors += grid[i + di][j + dj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (!grid[i][j] && neighbors === 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid.splice(0, grid.length, ...new_grid);
    }
}

cellular_automata(50, 50);