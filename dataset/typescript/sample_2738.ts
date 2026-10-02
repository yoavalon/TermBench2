function cellular_automata() {
    let grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        let new_grid = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                let live_neighbors = 0;
                for (let x = i - 1; x < i + 2; x++) {
                    for (let y = j - 1; y < j + 2; y++) {
                        if (x >= 0 && x < 3 && y >= 0 && y < 3 && (x !== i || y !== j) && grid[x][y]) {
                            live_neighbors += 1;
                        }
                    }
                }
                new_grid[i][j] = live_neighbors === 2 ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

cellular_automata();