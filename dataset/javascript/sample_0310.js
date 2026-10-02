function simulate() {
    const random = Math.random;
    let grid = Array.from({ length: 10 }, () => Array(10).fill(0));
    while (true) {
        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 10; j++) {
                let neighbors = [];
                for (let [dx, dy] of [[-1, 0], [1, 0], [0, -1], [0, 1]]) {
                    if (i + dx >= 0 && i + dx < 10 && j + dy >= 0 && j + dy < 10) {
                        neighbors.push(grid[i + dx][j + dy]);
                    }
                }
                if (neighbors.reduce((a, b) => a + b, 0) > 4) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = Math.floor(random() * 2);
                }
            }
        }
    }
}
simulate();