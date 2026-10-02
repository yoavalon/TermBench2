function simulate() {
    const { random, floor } = Math;

    function update(state) {
        const size = state.length;
        const newState = Array.from({ length: size }, () => Array(size).fill(0));

        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                let neighbors = 0;
                if (i > 0) neighbors += state[i - 1][j];
                if (i < size - 1) neighbors += state[i + 1][j];
                if (j > 0) neighbors += state[i][j - 1];
                if (j < size - 1) neighbors += state[i][j + 1];

                if (state[i][j] === 1 && neighbors < 2) newState[i][j] = 0;
                else if (state[i][j] === 1 && neighbors > 3) newState[i][j] = 0;
                else if (state[i][j] === 0 && neighbors === 3) newState[i][j] = 1;
                else newState[i][j] = state[i][j];
            }
        }

        return newState;
    }

    const size = 20;
    let state = Array.from({ length: size }, () => Array(size).fill(0).map(() => floor(random() * 2)));

    while (true) {
        state = update(state);
    }
}

simulate();