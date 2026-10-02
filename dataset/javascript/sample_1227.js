function cellular_automata(size, steps) {
    let grid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let _ = 0; _ < steps; _++) {
        let new_grid = Array.from({ length: size }, () => Array(size).fill(0));
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                let neighbors = 0;
                for (let dx of [-1, 0, 1]) {
                    for (let dy of [-1, 0, 1]) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = (neighbors === 3 || (grid[i][j] && neighbors === 2)) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
    return grid;
}
cellular_automata(10, 5);