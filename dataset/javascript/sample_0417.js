function update_cells(state) {
    let new_state = Array.from({ length: state.length }, () => Array(state[0].length).fill(0));
    for (let i = 0; i < state.length; i++) {
        for (let j = 0; j < state[0].length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(state.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(state[0].length, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += state[x][y];
                    }
                }
            }
            new_state[i][j] = (neighbors === 3) || (neighbors === 2 && state[i][j]) ? 1 : 0;
        }
    }
    return new_state;
}

function simulate(state) {
    while (true) {
        state = update_cells(state);
        for (let row of state) {
            console.log(row.map(cell => cell ? '█' : ' ').join(''));
        }
        console.log();
    }
}

function main() {
    let initial_state = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initial_state);
}

main();