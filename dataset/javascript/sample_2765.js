function cellular_automata(n) {
    let state = new Array(n).fill(0);
    state[Math.floor(n / 2)] = 1;
    while (true) {
        let new_state = new Array(n).fill(0);
        for (let i = 1; i < n - 1; i++) {
            new_state[i] = state[i - 1] ^ state[i + 1];
        }
        state = new_state;
    }
}

cellular_automata(30);