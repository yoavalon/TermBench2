function simulate(): void {
    import * as random from 'random';

    let grid: number[][] = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random.int(0, 1)));

    while (true) {
        let new_grid: number[][] = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => 0));

        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 10; j++) {
                let neighbors: number = 0;
                for (let dx of [-1, 0, 1]) {
                    for (let dy of [-1, 0, 1]) {
                        if (dx !== 0 || dy !== 0) {
                            if (0 <= i + dx && i + dx < 10 && 0 <= j + dy && j + dy < 10) {
                                neighbors += grid[i + dx][j + dy];
                            }
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