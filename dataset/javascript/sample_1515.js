function simulate() {
    const { random, floor } = Math;
    let state = Array.from({ length: 50 }, () => Array(50).fill(0).map(() => floor(random() * 2)));
    while (true) {
        let new_state = Array.from({ length: 50 }, () => Array(50).fill(0));
        for (let i = 1; i < 49; i++) {
            for (let j = 1; j < 49; j++) {
                let neighbors = 0;
                for (let di = -1; di <= 1; di++) {
                    for (let dj = -1; dj <= 1; dj++) {
                        neighbors += state[i + di][j + dj];
                    }
                }
                neighbors -= state[i][j];
                if (state[i][j] && (neighbors === 2 || neighbors === 3)) {
                    new_state[i][j] = 1;
                } else if (!state[i][j] && neighbors === 3) {
                    new_state[i][j] = 1;
                }
            }
        }
        state = new_state;
    }
}
simulate();