function cellularAutomata(width, height) {
    let grid = Array.from({ length: height }, () => Array(width).fill(0));
    while (true) {
        let newGrid = grid.map(row => [...row]);
        for (let i = 1; i < height - 1; i++) {
            for (let j = 1; j < width - 1; j++) {
                let neighbors = 0;
                for (let ni = -1; ni <= 1; ni++) {
                    for (let nj = -1; nj <= 1; nj++) {
                        neighbors += grid[i + ni][j + nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (!grid[i][j] && neighbors === 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        grid = newGrid;
    }
}
cellularAutomata(50, 50);