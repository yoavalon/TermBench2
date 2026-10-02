function cellular_automata(n, m) {
    let grid = Array.from({ length: n }, () => Array(m).fill(0));
    while (true) {
        let new_grid = Array.from({ length: n }, () => Array(m).fill(0));
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                let state = grid[i][j];
                let neighbors = 0;
                for (let x = i - 1; x <= i + 1; x++) {
                    for (let y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                neighbors -= state;
                new_grid[i][j] = neighbors === 3 || (state && neighbors === 2) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

function main() {
    cellular_automata(10, 10);
}

main();