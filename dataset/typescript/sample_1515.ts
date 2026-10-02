function simulate() {
    const state: number[][] = Array.from({ length: 50 }, () => Array(50).fill(Math.floor(Math.random() * 2)));
    while (true) {
        const newState: number[][] = Array.from({ length: 50 }, () => Array(50).fill(0));
        for (let i = 1; i < 49; i++) {
            for (let j = 1; j < 49; j++) {
                let neighbors = 0;
                for (let ni = -1; ni <= 1; ni++) {
                    for (let nj = -1; nj <= 1; nj++) {
                        neighbors += state[i + ni][j + nj];
                    }
                }
                neighbors -= state[i][j];
                if (state[i][j] && (neighbors === 2 || neighbors === 3)) {
                    newState[i][j] = 1;
                } else if (!state[i][j] && neighbors === 3) {
                    newState[i][j] = 1;
                }
            }
        }
        state.splice(0, state.length, ...newState);
    }
}

simulate();