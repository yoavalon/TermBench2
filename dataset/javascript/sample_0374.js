function simulate() {
    const random = require('random');
    let grid = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random.int(0, 1)));
    while (true) {
        let new_grid = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => 0));
        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 10; j++) {
                let neighbors = 0;
                for (let dx of [-1, 0, 1]) {
                    for (let dy of [-1, 0, 1]) {
                        if (dx === 0 && dy === 0) continue;
                        if (i + dx >= 0 && i + dx < 10 && j + dy >= 0 && j + dy < 10) {
                            neighbors += grid[i + dx][j + dy];
                        }
                    }
                }
                new_grid[i][j] = neighbors === 3 ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}
simulate();