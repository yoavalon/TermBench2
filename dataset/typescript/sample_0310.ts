function simulate() {
    import * as random from 'random';

    let grid: number[][] = Array.from({ length: 10 }, () => Array(10).fill(0));

    while (true) {
        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 10; j++) {
                let neighbors: number[] = [];
                for (let [dx, dy] of [(-1, 0), (1, 0), (0, -1), (0, 1)]) {
                    if (0 <= i + dx && i + dx < 10 && 0 <= j + dy && j + dy < 10) {
                        neighbors.push(grid[i + dx][j + dy]);
                    }
                }
                if (neighbors.reduce((a, b) => a + b, 0) > 4) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = random.int(2); // Assuming random.choice([0, 1]) is equivalent to random.int(2)
                }
            }
        }
    }
}

simulate();